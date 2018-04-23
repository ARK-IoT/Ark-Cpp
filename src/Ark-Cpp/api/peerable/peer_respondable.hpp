

#ifndef PEER_RESPONDABLE_HPP
#define PEER_RESPONDABLE_HPP

namespace ARK
{
namespace API
{
namespace Peer
{
namespace Respondable
{
/*************************************************
*		ARK::API::Peer::Respondable::version_t
*   @param:	char version[32], char build[32]
*
*   @brief:	Model for Loader Status API Response
**************************************************/
struct version_t
{
	public:
		char version[32];
		char build[32];
};
/*************************************************/

/*************************************************
*		ARK::API::Peer::Respondable::Version
*   @param:	char version{32], char build[32]
*   @methods:	printTo(Print& p)
*
*   @brief:	Model for Loader Status API Response
**************************************************/
struct Version :
		public version_t, Printable
{
	public:

		Version(
				const char* const newVersion,
				const char* const newBuild
		)
		{
			strncpy(version, newVersion, sizeof(version) / sizeof(version[0]));
			strncpy(build, newBuild, sizeof(build) / sizeof(build[0]));
		};

    virtual size_t printTo(Print& p) const
    {
      size_t size = 0;
        size += p.print("version: ");
        size += p.print(this->version);
        size += p.print("\nbuild: ");
        size += p.print(this->build);
      return size;
    };
};
/*************************************************/

/*************************************************/
/*************************************************/
/*  ARK::API::Peer::Respondable::Peers  */
//   struct Peers {
//     public:
//       // int count;
//       ARK::Peer list[10];// = {{}};
//       // PeersResponse(int);
//       String description();
//   };
/*************************************************/
/*************************************************/

};
};
};
};

/*************************************************/
/*************************************************/
/*  ARK::API::Peer::Respondable::Peers  */
/*  Description  */
// String ARK::API::Peer::Respondable::Peers::description() {
//   String resp;
//   if (this->count > 0) {
//     for (int i = 0; i < this->count; i++) {
//       resp += "\npeer ";
//       resp += i + 1;
//       resp += ":\n";
//       resp += this->list[i].description();
//       resp += "\n";
//     };
//   };
//   return resp;
// }
/*  ==================================  */
/*  ==========================================================================  */

#endif
