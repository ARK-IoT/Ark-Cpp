

#ifndef delegate_h
#define delegate_h

namespace ARK {

	/*  =============  */
	/*  ARK::Delegate  */
	struct Delegate {
		public:
			String username;
			Address address;
			Publickey publicKey;
			Balance vote;
			int producedblocks;
			int missedblocks;
			int rate;
			double approval;
			double productivity;

			Delegate();
			Delegate(String, Address, Publickey, Balance, int, int, int, double, double);

			String description();

			struct SearchResponse;
			struct ForgedByAccountResponse;
			struct NextForgersResponse;
	};
	/*  =============  */


	/*  =====================  */
	/*  ARK::DelegateResponse  */
  struct DelegatesResponse {
    public:
      int count;
      ARK::Delegate list[5];// = {{}};
      DelegatesResponse(int);
      String description();

  };
	/*  =====================  */

};


/*  ================================================  */


/*  =============  */
/*  ARK::Delegate  */

/*  Constructor  */
ARK::Delegate::Delegate() {
  username = "";
  address = { "" };
  publicKey = { "" };
  vote = { "" };
  producedblocks = 0;
  missedblocks = 0;
  rate = 0;
  approval = 0.00;
  productivity = 0.00;
}

/*  =====  */

/*  Constructor  */
ARK::Delegate::Delegate(
	String _username,
	Address _address,
	Publickey _publicKey,
	Balance _vote,
	int _producedblocks,
	int _missedblocks,
	int _rate,
	double _approval,
	double _productivity) :
		username(_username),
		address( { _address }),
		publicKey( { _publicKey } ),
		vote( { _vote } ),
		producedblocks(_producedblocks),
		missedblocks(_missedblocks),
		rate(_rate),
		approval(_approval),
		productivity(_productivity) {}
		
/*  =====  */

/*  Description  */
String ARK::Delegate::Delegate::description() {
  String resp;
    resp += "username: ";
        resp += this->username; resp += "\n";
    resp += "address.description: ";
        resp += this->address.description(); resp += "\n";
    resp += "publicKey.description: ";
        resp += this->publicKey.description(); resp += "\n";
    resp += "vote.ark: ";
        resp += this->vote.ark; resp += "\n";
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
/*  =====  */


/*  ================================================  */


/*  ============  */
/*  ARK::Delegate::Delegate::SearchResponse  */

/*  Definition  */
struct ARK::Delegate::Delegate::SearchResponse {
	public:
		String username;
		Address address;
		Publickey publicKey;
		Balance vote;
		int producedblocks;
		int missedblocks;
		SearchResponse(String, Address, Publickey, Balance, int, int);
		String description();
};

/*  =====  */

/*  Constructor  */
ARK::Delegate::Delegate::SearchResponse::SearchResponse (
	String _username,
	Address _address,
	Publickey _publicKey,
	Balance _vote,
	int _producedblocks,
	int _missedblocks ) {
		this->username = _username;
		this->address = { _address };
		this->publicKey = { _publicKey };
		this->vote = { _vote };
		this->producedblocks = _producedblocks;
		this->missedblocks = _missedblocks;
}

/*  =====  */

/*  Description  */
String ARK::Delegate::Delegate::SearchResponse::description() {
	String resp;
		resp += "username: ";
				resp += this->username; resp += "\n";
		resp += "address.description: ";
				resp += this->address.description(); resp += "\n";
		resp += "publicKey.description: ";
			resp += this->publicKey.description(); resp += "\n";
		resp += "vote.ark: ";
				resp += this->vote.ark; resp += "\n";
		resp += "producedblocks: ";
				resp += this->producedblocks; resp += "\n";
		resp += "missedblocks: ";
			resp += this->missedblocks;
	return resp;
}
/*  ============  */


/*  ================================================  */


/*  ============  */
/*  ARK::Delegate::Delegate::ForgedByAccountResponse  */

/*  Definition  */
struct ARK::Delegate::Delegate::ForgedByAccountResponse {
	public:
		Balance fees;
		Balance rewards;
		Balance forged;
		String description();
};

/*  =====  */

/*  Description  */
String ARK::Delegate::Delegate::ForgedByAccountResponse::description() {
	String resp;
		resp += "fees.ark: ";
				resp += this->fees.ark; resp += "\n";
		resp += "rewards.ark: ";
				resp += this->rewards.ark; resp += "\n";
		resp += "forged.ark: ";
			resp += this->forged.ark;
	return resp;
}
/*  ============  */


/*  ================================================  */


/*  ============  */
/*  ARK::Delegate::Delegate::NextForgersResponse  */

/*  Definition  */
struct ARK::Delegate::Delegate::NextForgersResponse {
	public:
		String currentBlock;
		String currentSlot;
		Publickey delegates[10];
		NextForgersResponse(String _currentBlock, String _currentSlot, Publickey _delegates[10]);
		String description();
};

/*  =====  */

/*  Constructor  */
ARK::Delegate::Delegate::NextForgersResponse::NextForgersResponse(String _currentBlock, String _currentSlot, Publickey _delegates[10]) {
	this->currentBlock = _currentBlock;
	this->currentSlot = _currentSlot;
	for (int i = 0; i < 10; i++) {
		this->delegates[i] = _delegates[i];
	};
}

/*  =====  */

/*  Description  */
String ARK::Delegate::Delegate::NextForgersResponse::description() {
	String resp;
		resp += "currentBlock: ";
				resp += this->currentBlock; resp += "\n";
		resp += "currentSlot: ";
				resp += this->currentSlot; resp += "\n";
		for (int i = 0; i < 10; i++ ) {
			resp += "delegate ";
			resp += i + 1;
			resp += ": \n publicKey: ";
			resp += delegates[i].description();
			resp += "\n";
		};
	return resp;
}
/*  ============  */


/*  ================================================  */


/*  =============  */
/*  ARK::DelegatesResponse  */

/*  Constructor  */
ARK::DelegatesResponse::DelegatesResponse(int _count){
  this->count = _count;
}

/*  =====  */

/*  Description  */
String ARK::DelegatesResponse::DelegatesResponse::description() {
  String resp;
  if (this->count > 0) {
    for (int i = 0; i < this->count; i++) {
      resp += "\ndelegate ";
      resp += i + 1;
      resp += ":\n";
      resp += this->list[i].description();
      resp += "\n";
    };
  };
  return resp;
}
/*  =============  */


/*  ========================  */





#endif
