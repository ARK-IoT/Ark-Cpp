#ifndef ARK_CRYPTO_SECP256K1_H
#define ARK_CRYPTO_SECP256K1_H

#include <bitcoin/key.h>
#include <bitcoin/random.h>

void ECC_Start();

void ECC_Stop();

bool secp256k1_ec_seckey_verify(const unsigned char *vch);
int ec_privkey_export_der(unsigned char *privkey, size_t *privkeylen, const unsigned char *key32, bool compressed);

CPubKey get_pub_key(const CKey& privkey);

bool ec_verify(const uint256 &hash, const std::vector<unsigned char>& vchSig);

#endif
