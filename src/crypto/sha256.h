#ifndef SHA256_H
#define SHA256_H

#include "Poco/Crypto/DigestEngine.h"

namespace ARK {
namespace Crypto {

class SHA256Engine : public Poco::Crypto::DigestEngine {
public:
	enum {
		BLOCK_SIZE = 64,
		DIGEST_SIZE = 32
	};

	SHA256Engine() : DigestEngine("SHA256") { }
};


}
}
#endif
