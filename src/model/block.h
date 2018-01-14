

#ifndef block_h
#define block_h

namespace ARK {
  
	struct Block {
		public:
			String id;
			int version;
			String timestamp;
			String height;
			String previousBlock;
			String numberOfTransactions;
			String totalAmount;
			String totalFee;
			String reward;
			String intpayloadLength;
			String payloadHash;
			String generatorPublicKey;
			String generatorId;
			String blockSignature;
			String confirmations;
			String totalForged;

			Block();
			Block(String, int, String, String, String, String, String, String, String, String, String, String, String, String, String, String);

			String description();

			struct BlockStatusResponse;
			struct BlockHeightResponse;

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
  id = "";
  version = 0;
  timestamp = "";
  height = "";
  previousBlock = "";
  numberOfTransactions = "";
  totalAmount = "";
  totalFee = "";
  reward = "";
  intpayloadLength = "";
  payloadHash = "";
  generatorPublicKey = "";
  generatorId = "";
  blockSignature = "";
  confirmations = "";
  totalForged = "";
}

ARK::Block::Block (
	String _id,
	int _version,
	String _timestamp,
	String _height,
	String _previousBlock,
	String _numberOfTransactions,
	String _totalAmount,
	String _totalFee,
	String _reward,
	String _intpayloadLength,
	String _payloadHash,
	String _generatorPublicKey,
	String _generatorId,
	String _blockSignature,
	String _confirmations,
	String _totalForged) :
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
			resp += this->totalForged;
  return resp;
}





struct ARK::Block::Block::BlockStatusResponse {
	public:
		String epoch;
		String height;
		String fee;
		int milestone;
		String nethash;
		String reward;
		String supply;
		BlockStatusResponse();
		BlockStatusResponse(String, String, String, int, String, String, String);
		String description();
};

ARK::Block::Block::BlockStatusResponse::BlockStatusResponse() { 
	this->epoch = "";
	this->height = "";
	this->fee = "";
	this->milestone = 0;
	this->nethash = "";
	this->reward = "";
	this->supply = "";
}

ARK::Block::Block::BlockStatusResponse::BlockStatusResponse (
	String _epoch,
	String _height,
	String _fee,
	int _milestone,
	String _nethash,
	String _reward,
	String _supply) :
		epoch(_epoch),
		height(_height),
		fee(_fee),
		milestone(_milestone),
		nethash(_nethash),
		reward(_reward),
		supply(_supply) {}

String ARK::Block::Block::BlockStatusResponse::description() {
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
				resp += this->supply;
	return resp;
}





struct ARK::Block::Block::BlockHeightResponse {
	public:
		String height;
		String id;
		String description();
};

String ARK::Block::Block::BlockHeightResponse::description() {
	String resp;
		resp += "height: ";
				resp += this->height; resp += "\n";
		resp += "id: ";
				resp += this->id;
	return resp;
}


#endif
