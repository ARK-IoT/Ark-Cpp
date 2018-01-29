

#ifndef peer_h
#define peer_h

namespace ARK {

/*  ================================================  */
	/*  =========  */
	/*  ARK::Peer  */
	struct Peer {
		public:
			String ip;
			int port;
			String version;
			int errors;
			String os;
			String height;
			String status;
			int delay;

			String description();
	};
	/*  =========  */
/*  ================================================  */

};

/*  ================================================  */
/*  =========  */
/*  Description  */
String ARK::Peer::Peer::description() {
	String resp;
		resp += "ip: ";
				resp += this->ip; resp += "\n";
		resp += "port: ";
				resp += this->port; resp += "\n";
		resp += "version: ";
				resp += this->version; resp += "\n";
		resp += "_errors: ";
				resp += this->errors; resp += "\n";
		resp += "os: ";
				resp += this->os; resp += "\n";
		resp += "height: ";
				resp += this->height; resp += "\n";
		resp += "status: ";
				resp += this->status; resp += "\n";
		resp += "delay: ";
				resp += this->delay;
	return resp;
}
/*  =========  */
/*  ================================================  */

#endif
