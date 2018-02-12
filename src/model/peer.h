

#ifndef peer_h
#define peer_h

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

            Peer(
                const char* const i,
                int p,
                const char* const v,
                int e,
                const char* const o,
                const char* const h,
                const char* const s,
                int d
            ) : ip(), port(p), version(), errors(e), os(), height(), status(), delay(d) {
                strncpy(ip, i, sizeof(ip) / sizeof(ip[0]));
                strncpy(version, v, sizeof(version) / sizeof(version[0]));
                strncpy(os, o, sizeof(os) / sizeof(os[0]));
                strncpy(height, h, sizeof(height) / sizeof(height[0]));
                strncpy(status, s, sizeof(status) / sizeof(status[0]));
            }

			void description(char* const buf, size_t size);
	};
	/*  =========  */
/*  ================================================  */

};

/*  ================================================  */
/*  =========  */
/*  Description  */
void ARK::Peer::Peer::description(char* const buf, size_t /*size*/) {
    strcpy(buf, "ip: ");
    strcat(buf, this->ip);
    strcat(buf, "\nport: ");
    auto len = strlen(buf);
    sprintf(buf + len, "%d", this->port);
    strcat(buf, "\nversion: ");
    strcat(buf, this->version);
    strcat(buf, "\nerrors: ");
    len = strlen(buf);
    sprintf(buf + len, "%d", this->errors);
    strcat(buf, "\nos: ");
    strcat(buf, this->os);
    strcat(buf, "\nheight: ");
    strcat(buf, this->height);
    strcat(buf, "\nstatus: ");
    strcat(buf, this->status);
    strcat(buf, "\ndelay: ");
    len = strlen(buf);
    sprintf(buf + len, "%d", this->delay);
}
/*  =========  */
/*  ================================================  */

#endif
