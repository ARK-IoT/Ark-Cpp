

#ifndef block_h
#define block_h

namespace ARK {

	/*  ==========  */
	/*  ARK::Block  */
	struct Block {
		public:
			String id;
			int version;
			String timestamp;
			String height;
			String previousBlock;
			String numberOfTransactions;
			Balance totalAmount;
			Balance totalFee;
			Balance reward;
			String intpayloadLength;
			Hash payloadHash;
			Publickey generatorPublicKey;
			Address generatorId;
			Signature blockSignature;
			String confirmations;
			String totalForged;

			Block();
			Block(
				String,
				int,
				String,
				String,
				String,
				String,
				Balance,
				Balance,
				Balance,
				String,
				Hash,
				Publickey,
				Address,
				Signature,
				String,
				String
			);

			String description();

			struct BlockStatusResponse;
			struct BlockHeightResponse;

	};
	/*  ==========  */


/*  ================================================  */


		/*  ===========  */
		/*  ARK::Blocks  */
		struct Blocks {
		public:
			Block blocks[] = {};
			int count;

			Blocks(){
				// this->blocks = { };
				this->count = 0;	
			};
			// Blocks(Block _blocks){
			// 	this->blocks = _blocks;
			// };
			// Blocks(int, double, int, int, int, int, double, double, int, int, String, String, String, String, int, int);
			// String description();
			// struct getStatusResponse;
	};
		/*  ===========  */

};
/*  ================================================  */


/*  ==========  */
/*  ARK::Block  */

/*  Constructor  */
ARK::Block::Block() {
  id = "";
  version = 0;
  timestamp = "";
  height = "";
  previousBlock = "";
  numberOfTransactions = "";
  totalAmount = { "" };
  totalFee = { "" };
  reward = { "" };
  intpayloadLength = "";
  payloadHash = { "" };
  generatorPublicKey = { "" };
  generatorId = { "" };
  blockSignature = { "" };
  confirmations = "";
  totalForged = "";
}

/*  =====  */

/*  Constructor  */
ARK::Block::Block (
	String _id,
	int _version,
	String _timestamp,
	String _height,
	String _previousBlock,
	String _numberOfTransactions,
	Balance _totalAmount,
	Balance _totalFee,
	Balance _reward,
	String _intpayloadLength,
	Hash _payloadHash,
	Publickey _generatorPublicKey,
	Address _generatorId,
	Signature _blockSignature,
	String _confirmations,
	String _totalForged) :
		id(_id),
		version(_version),
		timestamp(_timestamp),
		height(_height),
		previousBlock(_previousBlock),
		numberOfTransactions(_numberOfTransactions),
		totalAmount( Balance(_totalAmount) ),
		totalFee( Balance(_totalFee) ),
		reward( Balance(_reward) ),
		intpayloadLength(_intpayloadLength),
		payloadHash( Hash(_payloadHash) ),
		generatorPublicKey( Publickey(_generatorPublicKey) ),
		generatorId( Address(_generatorId) ) ,
		blockSignature( Signature(_blockSignature) ),
		confirmations(_confirmations),
		totalForged( _totalForged ) {}

/*  =====  */

/*  Description  */
String ARK::Block::Block::description() {
  String resp;
		resp += "id: ";
			resp += this->id; resp += "\n";
		resp += "version: ";
			resp += this->version; resp += "\n";
		resp += "timestamp: ";
			resp += this->timestamp; resp += "\n";
		resp += "height: ";
			resp += this->height; resp += "\n";
		resp += "previousBlock: ";
			resp += this->previousBlock; resp += "\n";
		resp += "numberOfTransactions: ";
			resp += this->numberOfTransactions; resp += "\n";
		resp += "totalAmount.ark: ";
			resp += this->totalAmount.ark; resp += "\n";
		resp += "totalFee.ark: ";
			resp += this->totalFee.ark; resp += "\n";
		resp += "reward.ark: ";
			resp += this->reward.ark; resp += "\n";
		resp += "intpayloadLength: ";
			resp += this->intpayloadLength; resp += "\n";
		resp += "payloadHash.description: ";
			resp += this->payloadHash.description(); resp += "\n";
		resp += "generatorPublicKey.description: ";
			resp += this->generatorPublicKey.description(); resp += "\n";
		resp += "generatorId.description: ";
			resp += this->generatorId.description(); resp += "\n";
		resp += "blockSignature.description: ";
			resp += this->blockSignature.description(); resp += "\n";
		resp += "confirmations: ";
			resp += this->confirmations; resp += "\n";
		resp += "totalForged: ";
			resp += this->totalForged;
  return resp;
}
/*  ==========  */


/*  ================================================  */


/*  ============  */
/*  ARK::Block::Block::BlockStatusResponse  */

/*  Definition  */
struct ARK::Block::Block::BlockStatusResponse {
	public:
		String epoch;
		String height;
		Balance fee;
		int milestone;
		Hash nethash;
		Balance reward;
		Balance supply;

		BlockStatusResponse();
		BlockStatusResponse(String, String, Balance, int, Hash, Balance, Balance);

		String description();
};

/*  =====  */

/*  Constructor  */
ARK::Block::Block::BlockStatusResponse::BlockStatusResponse() { 
	this->epoch = "";
	this->height = "";
	this->fee = { "" };
	this->milestone = 0;
	this->nethash = { "" };
	this->reward = { "" };
	this->supply = { "" };
}

/*  =====  */

/*  Constructor  */
ARK::Block::Block::BlockStatusResponse::BlockStatusResponse (
	String _epoch,
	String _height,
	Balance _fee,
	int _milestone,
	Hash _nethash,
	Balance _reward,
	Balance _supply) :
		epoch(_epoch),
		height(_height),
		fee( Balance(_fee) ),
		milestone(_milestone),
		nethash( Hash(_nethash) ),
		reward( Balance(_reward) ),
		supply( Balance(_supply) ) {}

/*  =====  */

/*  Description  */
String ARK::Block::Block::BlockStatusResponse::description() {
	String resp;
		resp += "epoch: ";
				resp += this->epoch; resp += "\n";
		resp += "height: ";
				resp += this->height; resp += "\n";
		resp += "fee.ark: ";
				resp += this->fee.ark; resp += "\n";
		resp += "milestone: ";
				resp += this->milestone; resp += "\n";
		resp += "nethash.description: ";
				resp += this->nethash.description(); resp += "\n";
		resp += "reward.ark: ";
				resp += this->reward.ark; resp += "\n";
		resp += "supply.ark: ";
				resp += this->supply.ark;
	return resp;
}
/*  ============  */


/*  ================================================  */


/*  ============  */
/*  ARK::Block::Block::BlockHeightResponse  */

/*  Definition  */
struct ARK::Block::Block::BlockHeightResponse {
	public:
		String height;
		String id;
		String description();
};

/*  =====  */

/*  Description  */
String ARK::Block::Block::BlockHeightResponse::description() {
	String resp;
		resp += "height: ";
				resp += this->height; resp += "\n";
		resp += "id: ";
				resp += this->id;
	return resp;
}
/*  ============  */


#endif
