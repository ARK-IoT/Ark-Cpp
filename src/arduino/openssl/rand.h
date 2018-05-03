#ifndef OPENSSL_RAND_H
#define OPENSSL_RAND_H


void RAND_add(const void *buf, int num, double entropy) {
	// convert entropy bytes to bits
	//RNG.stir(static_cast<const uint8_t*>(buf), num, static_cast<unsigned int>(entropy * 8));
}

int RAND_bytes(unsigned char *buf, int num) {
	//RNG.rand(buf, num);
	return 1;
}

#endif
 