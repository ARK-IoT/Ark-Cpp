

#ifndef peer_h
#define peer_h

#include <cstring>

namespace ARK {

/*  ================================================  */
	/*  =========  */
	/*  ARK::Peer  */
	struct Peer {
		public:
			char ip[40];
			int port;
			char version[64]; //TODO:  review array sizes
			int errors;
			char os[64];
			char height[64];
			char status[64];
			int delay;

			void description(char* const buf, size_t size);
	};
	/*  =========  */
/*  ================================================  */

};

/*  ================================================  */
/*  =========  */
/*  Description  */
void ARK::Peer::Peer::description(char* const buf, size_t size) {
    strcpy(buf, "ip: ");
    strcat(buf, this->ip);
    strcat(buf, "\port: ");
    sprintf(buf, "%d", this->port);
    strcat(buf, "\version: ");
    strcat(buf, this->version);
    strcat(buf, "\n_errors: ");
    sprintf(buf, "%d", this->errors);
    strcat(buf, "\nos: ");
    strcat(buf, this->os);
    strcat(buf, "\nheight: ");
    strcat(buf, this->height);
    strcat(buf, "\nstatus: ");
    strcat(buf, this->status);
    strcat(buf, "\ndelay: ");
    sprintf(buf, "%d", this->delay);
}
/*  =========  */
/*  ================================================  */

#endif
