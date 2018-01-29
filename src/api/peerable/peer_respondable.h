

#ifndef PEER_RESPONDABLE_H
#define PEER_RESPONDABLE_H

namespace ARK
{
namespace API
{
namespace Peer
{
namespace Respondable
{

/*  ==========================================================================  */
/*  ========================  */
/*  ARK::API::Peer::Respondable::Version  */
  struct Version {
    public:
      String version;
      String build;
      String description();
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


};
};
};
};




/*  ==========================================================================  */
/*  ========================  */
/*  ARK::API::Peer::Respondable::Version  */
/*  Description  */
String ARK::API::Peer::Respondable::Version::description() {
	String resp;
		resp += "version: ";
			resp += this->version; resp += "\n";
		resp += "build: ";
			resp += this->build; resp += "\n";
	return resp;
}
/*  ========================  */
/*  ==========================================================================  */



/*  ==========================================================================  */
/*  ==================================  */
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
