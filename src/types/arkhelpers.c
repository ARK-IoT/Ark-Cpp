/*******************************************************************************
*   Ark Wallet
*   (c) 2017 Ledger
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
********************************************************************************/

/* https://raw.githubusercontent.com/ArkEcosystem/ark-ledger/master/src/arkHelpers.c */

#include "arkHelpers.h"
#include "arkBase58.h"
#include <stdbool.h>

void ark_public_key_hash160(unsigned char WIDE *in, unsigned short inlen,
                            unsigned char *out) {
    union {
        cx_sha256_t shasha;
        cx_ripemd160_t riprip;
    } u;

    cx_ripemd160_init(&u.riprip);
    cx_hash(&u.riprip.header, CX_LAST, in, inlen, out);
}

unsigned short ark_public_key_to_encoded_base58(unsigned char WIDE *in,
                                                unsigned short inlen,
                                                unsigned char *out,
                                                unsigned short outlen,
                                                unsigned short version,
                                                unsigned char alreadyHashed) {
    unsigned char tmpBuffer[26];
    unsigned char checksumBuffer[32];
    cx_sha256_t hash;
    unsigned char versionSize = (version > 255 ? 2 : 1);

    if (version > 255) {
        tmpBuffer[0] = (version >> 8);
        tmpBuffer[1] = version;
    } else {
        tmpBuffer[0] = version;
    }

    if (!alreadyHashed) {
        ark_public_key_hash160(in, inlen, tmpBuffer + versionSize);
    } else {
        os_memmove(tmpBuffer + versionSize, in + versionSize, 20);
    }

    cx_sha256_init(&hash);
    cx_hash(&hash.header, CX_LAST, tmpBuffer, 20 + versionSize, checksumBuffer);
    cx_sha256_init(&hash);
    cx_hash(&hash.header, CX_LAST, checksumBuffer, 32, checksumBuffer);

    os_memmove(tmpBuffer + 20 + versionSize, checksumBuffer, 4);
    return ark_encode_base58(tmpBuffer, 24 + versionSize, out, outlen);
}

unsigned short ark_address_to_encoded_base58(unsigned char WIDE *in,
                                                unsigned short inlen,
                                                unsigned char *out,
                                                unsigned short outlen) {
    unsigned char tmpBuffer[inlen+4];
    unsigned char checksumBuffer[32];
    cx_sha256_t hash;

    cx_sha256_init(&hash);
    cx_hash(&hash.header, CX_LAST, in, inlen, checksumBuffer);
    cx_sha256_init(&hash);
    cx_hash(&hash.header, CX_LAST, checksumBuffer, 32, checksumBuffer);

    os_memmove(tmpBuffer + inlen, checksumBuffer, 4);
    return ark_encode_base58(tmpBuffer, inlen + 4, out, outlen);
}

unsigned short ark_decode_base58_address(unsigned char WIDE *in,
                                         unsigned short inlen,
                                         unsigned char *out,
                                         unsigned short outlen) {
    unsigned char hashBuffer[32];
    cx_sha256_t hash;
    outlen = ark_decode_base58(in, inlen, out, outlen);

    // Compute hash to verify address
    cx_sha256_init(&hash);
    cx_hash(&hash.header, CX_LAST, out, outlen - 4, hashBuffer);
    cx_sha256_init(&hash);
    cx_hash(&hash.header, CX_LAST, hashBuffer, 32, hashBuffer);

    if (os_memcmp(out + outlen - 4, hashBuffer, 4)) {
        THROW(INVALID_CHECKSUM);
    }

    return outlen;
}

unsigned short ark_compress_public_key(cx_ecfp_public_key_t *publicKey,
                                       uint8_t *out, uint32_t outlen) {
    if (outlen < 33) {
        THROW(EXCEPTION_OVERFLOW);
    }
    if (publicKey->curve == CX_CURVE_256K1) {
        out[0] = ((publicKey->W[64] & 1) ? 0x03 : 0x02);
        os_memmove(out + 1, publicKey->W + 1, 32);
    } else if (publicKey->curve == CX_CURVE_Ed25519) {
        uint8_t i;
        out[0] = 0xED;
        for (i = 0; i < 32; i++) {
            out[i + 1] = publicKey->W[64 - i];
        }
        if ((publicKey->W[32] & 1) != 0) {
            out[32] |= 0x80;
        }
    } else {
        THROW(EXCEPTION);
    }
    return 33;
}

#if 0
unsigned short ark_print_amount(uint64_t amount, uint8_t *out, uint32_t outlen) {
    uint64_t partInt;
    uint64_t partDecimal;
    partInt = amount / 1000000;
    partDecimal = amount - (partInt * 1000000);
    // TODO : handle properly
    if ((partInt > 0xFFFFFFFF) || (partDecimal > 0xFFFFFFFF)) {
        THROW(EXCEPTION);
    }
    if (partDecimal == 0) {
        snprintf(out, outlen, "%d", (uint32_t)partInt);
    }
    else {
        snprintf(out, outlen, "%d.%d", (uint32_t)partInt, (uint32_t)partDecimal);
    }
    return strlen(out);
}
#endif

bool adjustDecimals(char *src, uint32_t srcLength, char *target,
                    uint32_t targetLength, uint8_t decimals) {
    uint32_t startOffset;
    uint32_t lastZeroOffset = 0;
    uint32_t offset = 0;

    if ((srcLength == 1) && (*src == '0')) {
        if (targetLength < 2) {
            return false;
        }
        target[offset++] = '0';
        target[offset++] = '\0';
        return true;
    }
    if (srcLength <= decimals) {
        uint32_t delta = decimals - srcLength;
        if (targetLength < srcLength + 1 + 2 + delta) {
            return false;
        }
        target[offset++] = '0';
        target[offset++] = '.';
        for (uint32_t i = 0; i < delta; i++) {
            target[offset++] = '0';
        }
        startOffset = offset;
        for (uint32_t i = 0; i < srcLength; i++) {
            target[offset++] = src[i];
        }
        target[offset] = '\0';
    } else {
        uint32_t sourceOffset = 0;
        uint32_t delta = srcLength - decimals;
        if (targetLength < srcLength + 1 + 1) {
            return false;
        }
        while (offset < delta) {
            target[offset++] = src[sourceOffset++];
        }
        if (decimals != 0) {
            target[offset++] = '.';
        }
        startOffset = offset;
        while (sourceOffset < srcLength) {
            target[offset++] = src[sourceOffset++];
        }
        target[offset] = '\0';
    }
    for (uint32_t i = startOffset; i < offset; i++) {
        if (target[i] == '0') {
            if (lastZeroOffset == 0) {
                lastZeroOffset = i;
            }
        } else {
            lastZeroOffset = 0;
        }
    }
    if (lastZeroOffset != 0) {
        target[lastZeroOffset] = '\0';
        if (target[lastZeroOffset - 1] == '.') {
            target[lastZeroOffset - 1] = '\0';
        }
    }
    return true;
}

unsigned short ark_print_amount(uint64_t amount, uint8_t *out,
                                uint32_t outlen) {
    char tmp[20];
    char tmp2[25];
    uint32_t numDigits = 0, i;
    uint64_t base = 1;
    while (base <= amount) {
        base *= 10;
        numDigits++;
    }
    if (numDigits > sizeof(tmp) - 1) {
        THROW(EXCEPTION);
    }
    base /= 10;
    for (i = 0; i < numDigits; i++) {
        tmp[i] = '0' + ((amount / base) % 10);
        base /= 10;
    }
    tmp[i] = '\0';
    strcpy(tmp2, "ARK ");
    adjustDecimals(tmp, i, tmp2 + 4, 25, 8);
    if (strlen(tmp2) < outlen - 1) {
        strcpy(out, tmp2);
    } else {
        out[0] = '\0';
    }
    return strlen(out);
}