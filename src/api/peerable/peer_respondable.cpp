#include "api/peerable/peer_respondable.h"

namespace ARK
{
namespace API
{
namespace Peer
{
namespace Respondable
{

/*************************************************
*	Constructor
**************************************************/
Version::Version(
		const char* const newVersion,
		const char* const newBuild
)
{
	strncpy(this->version_, newVersion, sizeof(version_) / sizeof(version_[0]));
	strncpy(this->build_, newBuild, sizeof(build_) / sizeof(build_[0]));
};
/*************************************************/

/*************************************************
*
**************************************************/
size_t Version::printTo(Print& p) const
{
	size_t size = 0;
		size += p.print("version: ");
		size += p.print(this->version_);
		size += p.print("\nbuild: ");
		size += p.print(this->build_);
	return size;
};
/*************************************************/

};
};
};
};
