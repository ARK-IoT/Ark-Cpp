#include "peer_respondable.h"

/*  ==========================================================================  */
/*  ========================  */
/*  ARK::API::Peer::Respondable::Version  */
/*  Description  */
void ARK::API::Peer::Respondable::Version::description(char* const buf, size_t size) {
    strcpy(buf, "version: ");
    strcat(buf, this->version);
    strcat(buf, "\nbuild: ");
    strcat(buf, this->build);
    strcat(buf, "\n");
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
