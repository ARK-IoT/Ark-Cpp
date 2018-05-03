#include "utilities/platform.h"

#ifndef USE_IOT

#include "crypto/secp256k1.h"
#include <bitcoin/secp256k1/src/secp256k1.h>
#include <bitcoin/secp256k1/src/secp256k1_recovery.h>

static secp256k1_context* secp256k1_context_sign = nullptr;

namespace
{
/* Global secp256k1_context object used for verification. */
secp256k1_context* secp256k1_context_verify = nullptr;
} // namespace

/** These functions are taken from the libsecp256k1 distribution and are very ugly. */

/**
* This parses a format loosely based on a DER encoding of the ECPrivateKey type from
* section C.4 of SEC 1 <http://www.secg.org/sec1-v2.pdf>, with the following caveats:
*
* * The octet-length of the SEQUENCE must be encoded as 1 or 2 octets. It is not
*   required to be encoded as one octet if it is less than 256, as DER would require.
* * The octet-length of the SEQUENCE must not be greater than the remaining
*   length of the key encoding, but need not match it (i.e. the encoding may contain
*   junk after the encoded SEQUENCE).
* * The privateKey OCTET STRING is zero-filled on the left to 32 octets.
* * Anything after the encoding of the privateKey OCTET STRING is ignored, whether
*   or not it is validly encoded DER.
*
* out32 must point to an output buffer of length at least 32 bytes.
*/
static int ec_privkey_import_der(const secp256k1_context* ctx, unsigned char *out32, const unsigned char *privkey, size_t privkeylen) {
	const unsigned char *end = privkey + privkeylen;
	memset(out32, 0, 32);
	/* sequence header */
	if (end - privkey < 1 || *privkey != 0x30u) {
		return 0;
	}
	privkey++;
	/* sequence length constructor */
	if (end - privkey < 1 || !(*privkey & 0x80u)) {
		return 0;
	}
	ptrdiff_t lenb = *privkey & ~0x80u; privkey++;
	if (lenb < 1 || lenb > 2) {
		return 0;
	}
	if (end - privkey < lenb) {
		return 0;
	}
	/* sequence length */
	ptrdiff_t len = privkey[lenb - 1] | (lenb > 1 ? privkey[lenb - 2] << 8 : 0u);
	privkey += lenb;
	if (end - privkey < len) {
		return 0;
	}
	/* sequence element 0: version number (=1) */
	if (end - privkey < 3 || privkey[0] != 0x02u || privkey[1] != 0x01u || privkey[2] != 0x01u) {
		return 0;
	}
	privkey += 3;
	/* sequence element 1: octet string, up to 32 bytes */
	if (end - privkey < 2 || privkey[0] != 0x04u) {
		return 0;
	}
	ptrdiff_t oslen = privkey[1];
	privkey += 2;
	if (oslen > 32 || end - privkey < oslen) {
		return 0;
	}
	memcpy(out32 + (32 - oslen), privkey, oslen);
	if (!secp256k1_ec_seckey_verify(ctx, out32)) {
		memset(out32, 0, 32);
		return 0;
	}
	return 1;
}

/**
* This serializes to a DER encoding of the ECPrivateKey type from section C.4 of SEC 1
* <http://www.secg.org/sec1-v2.pdf>. The optional parameters and publicKey fields are
* included.
*
* privkey must point to an output buffer of length at least CKey::PRIVATE_KEY_SIZE bytes.
* privkeylen must initially be set to the size of the privkey buffer. Upon return it
* will be set to the number of bytes used in the buffer.
* key32 must point to a 32-byte raw private key.
*/
static int ec_privkey_export_der(const secp256k1_context *ctx, unsigned char *privkey, size_t *privkeylen, const unsigned char *key32, int compressed) {
	assert(*privkeylen >= CKey::PRIVATE_KEY_SIZE);
	secp256k1_pubkey pubkey;
	size_t pubkeylen = 0;
	if (!secp256k1_ec_pubkey_create(ctx, &pubkey, key32)) {
		*privkeylen = 0;
		return 0;
	}
	if (compressed) {
		static const unsigned char begin[] = {
			0x30,0x81,0xD3,0x02,0x01,0x01,0x04,0x20
		};
		static const unsigned char middle[] = {
			0xA0,0x81,0x85,0x30,0x81,0x82,0x02,0x01,0x01,0x30,0x2C,0x06,0x07,0x2A,0x86,0x48,
			0xCE,0x3D,0x01,0x01,0x02,0x21,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
			0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
			0xFF,0xFF,0xFE,0xFF,0xFF,0xFC,0x2F,0x30,0x06,0x04,0x01,0x00,0x04,0x01,0x07,0x04,
			0x21,0x02,0x79,0xBE,0x66,0x7E,0xF9,0xDC,0xBB,0xAC,0x55,0xA0,0x62,0x95,0xCE,0x87,
			0x0B,0x07,0x02,0x9B,0xFC,0xDB,0x2D,0xCE,0x28,0xD9,0x59,0xF2,0x81,0x5B,0x16,0xF8,
			0x17,0x98,0x02,0x21,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
			0xFF,0xFF,0xFF,0xFF,0xFE,0xBA,0xAE,0xDC,0xE6,0xAF,0x48,0xA0,0x3B,0xBF,0xD2,0x5E,
			0x8C,0xD0,0x36,0x41,0x41,0x02,0x01,0x01,0xA1,0x24,0x03,0x22,0x00
		};
		unsigned char *ptr = privkey;
		memcpy(ptr, begin, sizeof(begin)); ptr += sizeof(begin);
		memcpy(ptr, key32, 32); ptr += 32;
		memcpy(ptr, middle, sizeof(middle)); ptr += sizeof(middle);
		pubkeylen = CPubKey::COMPRESSED_PUBLIC_KEY_SIZE;
		secp256k1_ec_pubkey_serialize(ctx, ptr, &pubkeylen, &pubkey, SECP256K1_EC_COMPRESSED);
		ptr += pubkeylen;
		*privkeylen = ptr - privkey;
		assert(*privkeylen == CKey::COMPRESSED_PRIVATE_KEY_SIZE);
	}
	else {
		static const unsigned char begin[] = {
			0x30,0x82,0x01,0x13,0x02,0x01,0x01,0x04,0x20
		};
		static const unsigned char middle[] = {
			0xA0,0x81,0xA5,0x30,0x81,0xA2,0x02,0x01,0x01,0x30,0x2C,0x06,0x07,0x2A,0x86,0x48,
			0xCE,0x3D,0x01,0x01,0x02,0x21,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
			0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
			0xFF,0xFF,0xFE,0xFF,0xFF,0xFC,0x2F,0x30,0x06,0x04,0x01,0x00,0x04,0x01,0x07,0x04,
			0x41,0x04,0x79,0xBE,0x66,0x7E,0xF9,0xDC,0xBB,0xAC,0x55,0xA0,0x62,0x95,0xCE,0x87,
			0x0B,0x07,0x02,0x9B,0xFC,0xDB,0x2D,0xCE,0x28,0xD9,0x59,0xF2,0x81,0x5B,0x16,0xF8,
			0x17,0x98,0x48,0x3A,0xDA,0x77,0x26,0xA3,0xC4,0x65,0x5D,0xA4,0xFB,0xFC,0x0E,0x11,
			0x08,0xA8,0xFD,0x17,0xB4,0x48,0xA6,0x85,0x54,0x19,0x9C,0x47,0xD0,0x8F,0xFB,0x10,
			0xD4,0xB8,0x02,0x21,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
			0xFF,0xFF,0xFF,0xFF,0xFE,0xBA,0xAE,0xDC,0xE6,0xAF,0x48,0xA0,0x3B,0xBF,0xD2,0x5E,
			0x8C,0xD0,0x36,0x41,0x41,0x02,0x01,0x01,0xA1,0x44,0x03,0x42,0x00
		};
		unsigned char *ptr = privkey;
		memcpy(ptr, begin, sizeof(begin)); ptr += sizeof(begin);
		memcpy(ptr, key32, 32); ptr += 32;
		memcpy(ptr, middle, sizeof(middle)); ptr += sizeof(middle);
		pubkeylen = CPubKey::PUBLIC_KEY_SIZE;
		secp256k1_ec_pubkey_serialize(ctx, ptr, &pubkeylen, &pubkey, SECP256K1_EC_UNCOMPRESSED);
		ptr += pubkeylen;
		*privkeylen = ptr - privkey;
		assert(*privkeylen == CKey::PRIVATE_KEY_SIZE);
	}
	return 1;
}

/** This function is taken from the libsecp256k1 distribution and implements
 *  DER parsing for ECDSA signatures, while supporting an arbitrary subset of
 *  format violations.
 *
 *  Supported violations include negative integers, excessive padding, garbage
 *  at the end, and overly long length descriptors. This is safe to use in
 *  Bitcoin because since the activation of BIP66, signatures are verified to be
 *  strict DER before being passed to this module, and we know it supports all
 *  violations present in the blockchain before that point.
 */
static int ecdsa_signature_parse_der_lax(const secp256k1_context* ctx, secp256k1_ecdsa_signature* sig, const unsigned char *input, size_t inputlen) {
    size_t rpos, rlen, spos, slen;
    size_t pos = 0;
    size_t lenbyte;
    unsigned char tmpsig[64] = {0};
    int overflow = 0;

    /* Hack to initialize sig with a correctly-parsed but invalid signature. */
    secp256k1_ecdsa_signature_parse_compact(ctx, sig, tmpsig);

    /* Sequence tag byte */
    if (pos == inputlen || input[pos] != 0x30) {
        return 0;
    }
    pos++;

    /* Sequence length bytes */
    if (pos == inputlen) {
        return 0;
    }
    lenbyte = input[pos++];
    if (lenbyte & 0x80) {
        lenbyte -= 0x80;
        if (lenbyte > inputlen - pos) {
            return 0;
        }
        pos += lenbyte;
    }

    /* Integer tag byte for R */
    if (pos == inputlen || input[pos] != 0x02) {
        return 0;
    }
    pos++;

    /* Integer length for R */
    if (pos == inputlen) {
        return 0;
    }
    lenbyte = input[pos++];
    if (lenbyte & 0x80) {
        lenbyte -= 0x80;
        if (lenbyte > inputlen - pos) {
            return 0;
        }
        while (lenbyte > 0 && input[pos] == 0) {
            pos++;
            lenbyte--;
        }
        static_assert(sizeof(size_t) >= 4, "size_t too small");
        if (lenbyte >= 4) {
            return 0;
        }
        rlen = 0;
        while (lenbyte > 0) {
            rlen = (rlen << 8) + input[pos];
            pos++;
            lenbyte--;
        }
    } else {
        rlen = lenbyte;
    }
    if (rlen > inputlen - pos) {
        return 0;
    }
    rpos = pos;
    pos += rlen;

    /* Integer tag byte for S */
    if (pos == inputlen || input[pos] != 0x02) {
        return 0;
    }
    pos++;

    /* Integer length for S */
    if (pos == inputlen) {
        return 0;
    }
    lenbyte = input[pos++];
    if (lenbyte & 0x80) {
        lenbyte -= 0x80;
        if (lenbyte > inputlen - pos) {
            return 0;
        }
        while (lenbyte > 0 && input[pos] == 0) {
            pos++;
            lenbyte--;
        }
        static_assert(sizeof(size_t) >= 4, "size_t too small");
        if (lenbyte >= 4) {
            return 0;
        }
        slen = 0;
        while (lenbyte > 0) {
            slen = (slen << 8) + input[pos];
            pos++;
            lenbyte--;
        }
    } else {
        slen = lenbyte;
    }
    if (slen > inputlen - pos) {
        return 0;
    }
    spos = pos;

    /* Ignore leading zeroes in R */
    while (rlen > 0 && input[rpos] == 0) {
        rlen--;
        rpos++;
    }
    /* Copy R value */
    if (rlen > 32) {
        overflow = 1;
    } else {
        memcpy(tmpsig + 32 - rlen, input + rpos, rlen);
    }

    /* Ignore leading zeroes in S */
    while (slen > 0 && input[spos] == 0) {
        slen--;
        spos++;
    }
    /* Copy S value */
    if (slen > 32) {
        overflow = 1;
    } else {
        memcpy(tmpsig + 64 - slen, input + spos, slen);
    }

    if (!overflow) {
        overflow = !secp256k1_ecdsa_signature_parse_compact(ctx, sig, tmpsig);
    }
    if (overflow) {
        /* Overwrite the result again with a correctly-parsed but invalid
           signature if parsing failed. */
        memset(tmpsig, 0, 64);
        secp256k1_ecdsa_signature_parse_compact(ctx, sig, tmpsig);
    }
    return 1;
}

bool secp256k1_ec_seckey_verify(const unsigned char *vch) {
	return secp256k1_ec_seckey_verify(secp256k1_context_sign, vch);
}

int ec_privkey_export_der(unsigned char *privkey, size_t *privkeylen, const unsigned char *key32, bool compressed) {
	return ec_privkey_export_der(secp256k1_context_sign, privkey, privkeylen, key32, compressed ? SECP256K1_EC_COMPRESSED : SECP256K1_EC_UNCOMPRESSED);
}

CPubKey get_pub_key(const CKey& privkey) {
	assert(privkey.IsValid());
	secp256k1_pubkey pubkey;
	size_t clen = CPubKey::PUBLIC_KEY_SIZE;
	CPubKey result;
	int ret = secp256k1_ec_pubkey_create(secp256k1_context_sign, &pubkey, privkey.begin());
	assert(ret);
	secp256k1_ec_pubkey_serialize(secp256k1_context_sign, (unsigned char*)result.begin(), &clen, &pubkey, privkey.IsCompressed() ? SECP256K1_EC_COMPRESSED : SECP256K1_EC_UNCOMPRESSED);
	assert(result.size() == clen);
	assert(result.IsValid());
	return result;
}

bool ec_verify(const uint256 &hash, const std::vector<unsigned char>& vchSig) {
	secp256k1_pubkey pubkey;
    secp256k1_ecdsa_signature sig;
    if (!secp256k1_ec_pubkey_parse(secp256k1_context_verify, &pubkey, &(*this)[0], size())) {
        return false;
    }
    if (!ecdsa_signature_parse_der_lax(secp256k1_context_verify, &sig, vchSig.data(), vchSig.size())) {
        return false;
    }
    /* libsecp256k1's ECDSA verification requires lower-S signatures, which have
     * not historically been enforced in Bitcoin, so normalize them first. */
    secp256k1_ecdsa_signature_normalize(secp256k1_context_verify, &sig, &sig);
    return secp256k1_ecdsa_verify(secp256k1_context_verify, &sig, hash.begin(), &pubkey);
}

void ECC_Start() {
	assert(secp256k1_context_sign == nullptr);

	secp256k1_context *ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN);
	assert(ctx != nullptr);

	{
		// Pass in a random blinding seed to the secp256k1 context.
		//std::vector<unsigned char, secure_allocator<unsigned char>> vseed(32);
		std::vector<unsigned char> vseed(32);
		GetRandBytes(vseed.data(), 32);
		bool ret = secp256k1_context_randomize(ctx, vseed.data());
		assert(ret);
	}

	secp256k1_context_sign = ctx;
}

void ECC_Stop() {
	secp256k1_context *ctx = secp256k1_context_sign;
	secp256k1_context_sign = nullptr;

	if (ctx) {
		secp256k1_context_destroy(ctx);
	}
}

#endif // USE_IOT