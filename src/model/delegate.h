

#ifndef delegate_h
#define delegate_h

namespace ARK {

	struct Delegate {
		public:
			String username;
			String address;
			String publicKey;
			String vote;
			int producedblocks;
			int missedblocks;
			int rate;
			double approval;
			double productivity;

			Delegate();
			Delegate(String, String, String, String, int, int, int, double, double);

			String description();

			struct NextForgersResponse;
			struct ForgedByAccountResponse;
			struct SearchResponse;
	};

};


ARK::Delegate::Delegate() {
  username = "";
  address = "";
  publicKey = "";
  vote = "";
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
	String _vote,
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
        resp += this->productivity; resp += "%";
  return resp;
}




struct ARK::Delegate::Delegate::NextForgersResponse {
	public:
		String currentBlock;
		String currentSlot;
		String delegates[10];
		NextForgersResponse(String _currentBlock, String _currentSlot, String _delegates[10]);
		String description();
};

ARK::Delegate::Delegate::NextForgersResponse::NextForgersResponse(String _currentBlock, String _currentSlot, String _delegates[10]) {
	this->currentBlock = _currentBlock;
	this->currentSlot = _currentSlot;
	for (int i = 0; i < 10; i++) {
		this->delegates[i] = _delegates[i];
	};
}

String ARK::Delegate::Delegate::NextForgersResponse::description() {
	String resp;
		resp += "currentBlock: ";
				resp += this->currentBlock; resp += "\n";
		resp += "currentSlot: ";
				resp += this->currentSlot; resp += "\n";
		for (int i = 0; i < 10; i++ ) {
			resp += "delegate ";
			resp += i + 1;
			resp += ": \n	";
			resp += delegates[i];
			resp += "\n";
		};
	return resp;
}





struct ARK::Delegate::Delegate::ForgedByAccountResponse {
	public:
		String fees;
		String rewards;
		String forged;
		String description();
};



String ARK::Delegate::Delegate::ForgedByAccountResponse::description() {
	String resp;
		resp += "fees: ";
				resp += this->fees; resp += "\n";
		resp += "rewards: ";
				resp += this->rewards; resp += "\n";
		resp += "forged: ";
			resp += this->forged;
	return resp;
}





struct ARK::Delegate::Delegate::SearchResponse {
	public:
		String username;
		String address;
		String publicKey;
		String vote;
		int producedblocks;
		int missedblocks;
		SearchResponse(String, String, String, String, int, int);
		String description();
};

ARK::Delegate::Delegate::SearchResponse::SearchResponse (
	String _username,
	String _address,
	String _publicKey,
	String _vote,
	int _producedblocks,
	int _missedblocks ) {
		this->username = _username;
		this->address = _address;
		this->publicKey = _publicKey;
		this->vote = _vote;
		this->producedblocks = _producedblocks;
		this->missedblocks = _missedblocks;
}

String ARK::Delegate::Delegate::SearchResponse::description() {
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
			resp += this->missedblocks;
	return resp;
}

#endif
