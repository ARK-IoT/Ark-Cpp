

#ifndef PEER_RESPONDABLE_H
#define PEER_RESPONDABLE_H

#include <cstring>

namespace ARK {
namespace API {
namespace Peer {
namespace Respondable {

/*  ==========================================================================  */
/*  ========================  */
/*  ARK::API::Peer::Respondable::Version  */
class Version {
private:
	char version_[64];  //TODO: review sizes
	char build_[64];

public:
	Version(const char* const v, const char* const b) : version_(), build_() {
		strncpy(version_, v, sizeof(version_) / sizeof(version_[0]));
		strncpy(build_, b, sizeof(build_) / sizeof(build_[0]));
	}

	const char* version() const noexcept { return version_; }
	const char* build() const noexcept { return build_; }

	void description(char* const buf, size_t size);
};
/*  ========================  */
/*  ==========================================================================  */


/*  ==========================================================================  */
/*  ==================================  */
/*  ARK::API::Peer::Respondable::Peers  */
//   struct Peers {
//     public:
//       // int count;
//       ARK::Peer list[10];// = {{}};
//       // PeersResponse(int);
//       String description();
//   };
/*  ==================================  */
/*  ==========================================================================  */


}
}
}
}

#endif
