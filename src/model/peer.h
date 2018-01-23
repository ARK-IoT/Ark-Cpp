

#ifndef peer_h
#define peer_h

namespace ARK {

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

			Peer();
			Peer(String, int, String, int, String, String, String, int);
			
			String description();
			
			struct Version;
			struct PeersResponse;

	};
	/*  =========  */


};




/*  =========  */
/*  ARK::Peer  */

/*  Constructor  */
ARK::Peer::Peer() {
	this->ip = "";
	this->port = 0;
	this->version = "";
	this->errors = 0;
	this->os = "";
	this->height = "";
	this->status = "";
	this->delay = 0;
}

/*  =====  */

/*  Constructor  */
ARK::Peer::Peer(String _ip, int _port, String _version, int _errors, String _os, String _height, String _status, int _delay) {
		this->ip = _ip;
		this->port = _port;
		this->version = _version;
		this->errors = _errors;
		this->os = _os;
		this->height = _height;
		this->status = _status;
		this->delay = _delay;
}

/*  =====  */

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


/*  ========================  */
/*  ARK::Peer::Peer::Version  */

/*  Definition  */
struct ARK::Peer::Peer::Version {
	public:
		String version;
		String build;
		Version();
		Version(String _version, String _build);
		String description();
};

/*  =====  */

/*  Constructor  */
ARK::Peer::Peer::Version::Version() {
	this->version = "";
	this->build = "";
}

/*  =====  */

/*  Constructor  */
ARK::Peer::Version::Version(String _version, String _build) {
	this->version = _version;
	this->build = _build;
}

/*  =====  */

/*  Description  */
String ARK::Peer::Version::description() {
	String resp;
		resp += "version: ";
			resp += this->version; resp += "\n";
		resp += "build: ";
			resp += this->build; resp += "\n";
	return resp;
}
/*  ========================  */


/*  ================================================  */


/*  ==============================  */
/*  ARK::Peer::Peer::PeersResponse  */

/*  Definition  */
struct ARK::Peer::Peer::PeersResponse {
	public:
		int count;
		ARK::Peer list[10];// = {{}};
		PeersResponse(int);
		String description();
};

/*  =====  */

/*  Constructor  */
ARK::Peer::Peer::PeersResponse::PeersResponse(int _count){
  this->count = _count;
}

/*  =====  */

/*  Description  */
String ARK::Peer::Peer::PeersResponse::PeersResponse::description() {
  String resp;
  if (this->count > 0) {
    for (int i = 0; i < this->count; i++) {
      resp += "\npeer ";
      resp += i + 1;
      resp += ":\n";
      resp += this->list[i].description();
      resp += "\n";
    };
  };
  return resp;
}
/*  ==============================  */


#endif
