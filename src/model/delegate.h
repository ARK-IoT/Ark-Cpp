

#ifndef delegate_h
#define delegate_h

namespace ARK {

	struct Delegate {
		public:
			String username;
			String address;
			String publicKey;
			int vote;
			int producedblocks;
			int missedblocks;
			int rate;
			double approval;
			double productivity;

			Delegate();
    	Delegate(String, String, String, int, int, int, int, double, double);

      String description();

	};

};


ARK::Delegate::Delegate() {
  username = "";
  address = "";
  publicKey = "";
  vote = 0;
  producedblocks = 0;
  missedblocks = 0;
  rate = 0;
  approval = 0.00;
  productivity = 0.00;
}

ARK::Delegate::Delegate(
	String _username,
	String _address,
	String _publicKey,
	int _vote,
	int _producedblocks,
	int _missedblocks,
	int _rate,
	double _approval,
	double _productivity) :
		username(_username),
		address(_address),
		publicKey(_publicKey),
		vote(_vote),
		producedblocks(_producedblocks),
		missedblocks(_missedblocks),
		rate(_rate),
		approval(_approval),
		productivity(_productivity) {}


String ARK::Delegate::Delegate::description() {
  String resp;
    resp += "username: ";
        resp += this->username; resp += "\n";
    resp += "address: ";
        resp += this->address; resp += "\n";
    resp += "publicKey: ";
        resp += this->publicKey; resp += "\n";
    resp += "vote: ";
        resp += this->vote; resp += "\n";
    resp += "producedblocks: ";
        resp += this->producedblocks; resp += "\n";
    resp += "missedblocks: ";
        resp += this->missedblocks; resp += "\n";
    resp += "rate: ";
        resp += this->rate; resp += "\n";
    resp += "approval: ";
        resp += this->approval; resp += "%\n";
    resp += "productivity: ";
        resp += this->productivity; resp += "%\n";
  return resp;
}


#endif
