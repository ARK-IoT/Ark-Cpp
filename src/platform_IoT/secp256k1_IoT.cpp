#include "utilities/platform.h"

#include "crypto/secp256k1.h"

#include <uECC.h>


void ECC_Start() {
}

void ECC_Stop() {
}

bool secp256k1_ec_seckey_verify(const unsigned char *vch) {
	const uECC_Curve_t* curve = uECC_secp256k1();
	return uECC_verify()
}

int ec_privkey_export_der(unsigned char *privkey, size_t *privkeylen, const unsigned char *key32, bool compressed) {
}

CPubKey get_pub_key(const CKey& privkey) {
}

bool ec_verify(const uint256 &hash, const std::vector<unsigned char>& vchSig) {
}