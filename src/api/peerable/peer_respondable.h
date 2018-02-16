

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

/*************************************************
*	ARK::API::Peer::Respondable::Version
*
*   @variables:
*			bool loaded;
*			int now;
*			char blocksCount[64];
*
*   @methods:	printTo(HardwareSerial &serial)
*
*   @description:
*			Model for Loader Status API Response
*
**************************************************/
struct Version
{
	public:
		const char* version;
		const char* build;
    
		void printTo(HardwareSerial &serial);
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


/*************************************************
*	ARK::API::Peer::Respondable::Version
*
*   @methods:	printTo(HardwareSerial &serial)
*
*   @description:
*     Prints API Peer Version Response to Serial
*
**************************************************/
void ARK::API::Peer::Respondable::Version::printTo(HardwareSerial &serial)
{
  serial.print("\nversion: ");
  serial.print(this->version);
  serial.print("\nbuild: ");
  serial.print(this->build);
  serial.print("\n");
	serial.flush();
}
/*************************************************/



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
