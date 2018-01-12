

#ifndef block_h
#define block_h

namespace ARK {
  
	struct Block {
		public:
			int id;
			int version;
			int timestamp;
			int height;
			int previousBlock;
			int numberOfTransactions;
			int totalAmount;
			int totalFee;
			int reward;
			int intpayloadLength;
			String payloadHash;
			String generatorPublicKey;
			String generatorId;
			String blockSignature;
			int confirmations;
			int totalForged;

			Block();
			Block(int, int, int, int, int, int, int, int, int, int, String, String, String, String, int, int);

			String description();

			struct getStatusResponse;

	};

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

};


ARK::Block::Block() {
  id = 0;
  version = 0;
  timestamp = 0;
  height = 0;
  previousBlock = 0;
  numberOfTransactions = 0;
  totalAmount = 0;
  totalFee = 0;
  reward = 0;
  intpayloadLength = 0;
  payloadHash = "";
  generatorPublicKey = "";
  generatorId = "";
  blockSignature = "";
  confirmations = 0;
  totalForged = 0;
}

ARK::Block::Block (
	int _id,
	int _version,
	int _timestamp,
	int _height,
	int _previousBlock,
	int _numberOfTransactions,
	int _totalAmount,
	int _totalFee,
	int _reward,
	int _intpayloadLength,
	String _payloadHash,
	String _generatorPublicKey,
	String _generatorId,
	String _blockSignature,
	int _confirmations,
	int _totalForged) :
		id(_id),
		version(_version),
		timestamp(_timestamp),
		height(_height),
		previousBlock(_previousBlock),
		numberOfTransactions(_numberOfTransactions),
		totalAmount(_totalAmount),
		totalFee(_totalFee),
		reward(_reward),
		intpayloadLength(_intpayloadLength),
		payloadHash(_payloadHash),
		generatorPublicKey(_generatorPublicKey),
		generatorId(_generatorId),
		blockSignature(_blockSignature),
		confirmations(_confirmations),
		totalForged(_totalForged) {}


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
		resp += "totalAmount: ";
			resp += this->totalAmount; resp += "\n";
		resp += "totalFee: ";
			resp += this->totalFee; resp += "\n";
		resp += "reward: ";
			resp += this->reward; resp += "\n";
		resp += "intpayloadLength: ";
			resp += this->intpayloadLength; resp += "\n";
		resp += "payloadHash: ";
			resp += this->payloadHash; resp += "\n";
		resp += "generatorPublicKey: ";
			resp += this->generatorPublicKey; resp += "\n";
		resp += "generatorId: ";
			resp += this->generatorId; resp += "\n";
		resp += "blockSignature: ";
			resp += this->blockSignature; resp += "\n";
		resp += "confirmations: ";
			resp += this->confirmations; resp += "\n";
		resp += "totalForged: ";
			resp += this->totalForged; resp += "\n";
  return resp;
}





struct ARK::Block::Block::getStatusResponse {
	public:
		String epoch;
		int height;
		int fee;
		int milestone;
		String nethash;
		int reward;
		int supply;

		getStatusResponse();
		getStatusResponse(String, int, int, int, String, int, int);

		String description();
};


ARK::Block::Block::getStatusResponse::getStatusResponse() { 
	this->epoch = "";
	this->height = 0000000000;
	this->fee = 000000000;
	this->milestone = 0;
	this->nethash = "";
	this->reward = 000000000;
	this->supply = 0000000000;
}


ARK::Block::Block::getStatusResponse::getStatusResponse (
	String _epoch,
	int _height,
	int _fee,
	int _milestone,
	String _nethash,
	int _reward,
	int _supply) :
		epoch(_epoch),
		height(_height),
		fee(_fee),
		milestone(_milestone),
		nethash(_nethash),
		reward(_reward),
		supply(_supply) {}


String ARK::Block::Block::getStatusResponse::description() {
	String resp;
		resp += "epoch: ";
				resp += this->epoch; resp += "\n";
		resp += "height: ";
				resp += this->height; resp += "\n";
		resp += "fee: ";
				resp += this->fee; resp += "\n";
		resp += "milestone: ";
				resp += this->milestone; resp += "\n";
		resp += "nethash: ";
				resp += this->nethash; resp += "\n";
		resp += "reward: ";
				resp += this->reward; resp += "\n";
		resp += "supply: ";
				resp += this->supply; resp += "\n";
	return resp;
}



#endif
