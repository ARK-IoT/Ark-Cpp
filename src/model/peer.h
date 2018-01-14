

#ifndef peer_h
#define peer_h

namespace ARK {

	struct Peer {
		public:
			String ip;
			int port;
			String version;
			int errors;
			String os;
			int height;
			String status;
			int delay;

			Peer();
			Peer( String _ip, int _port, String _version, int _errors, String _os, int _height, String _status, int _delay);
			
			String description();
			
			struct Version;
	};

};


ARK::Peer::Peer() {
	this->ip = "";
	this->port = 0;
	this->version = "";
	this->errors = 0;
	this->os = "";
	this->height = 0;
	this->status = "";
	this->delay = 0;
}
ARK::Peer::Peer(String _ip, int _port, String _version, int _errors, String _os, int _height, String _status, int _delay) {
		this->ip = _ip;
		this->port = _port;
		this->version = _version;
		this->errors = _errors;
		this->os = _os;
		this->height = _height;
		this->status = _status;
		this->delay = _delay;
}
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




struct ARK::Peer::Peer::Version {
	public:
		String version;
		String build;
		Version();
		Version(String _version, String _build);
		String description();
};
ARK::Peer::Version::Version() {
	this->version = "";
	this->build = "";
}
ARK::Peer::Version::Version(String _version, String _build) {
	this->version = _version;
	this->build = _build;
}
String ARK::Peer::Version::Version::description() {
	String resp;
		resp += "version: ";
			resp += this->version; resp += "\n";
		resp += "build: ";
			resp += this->build; resp += "\n";
	return resp;
}


#endif
