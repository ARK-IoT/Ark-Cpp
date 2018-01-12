

#ifndef transport_h
#define transport_h

namespace ARK {
    
    struct TransportPeerHeader {
      public:
        long int id;
        long int height;
        long double version;
        long double totalAmount;
        long double totalFee;
        long double reward;
        String payloadHash;
        int payloadLength;
        long int timestamp;
        long int numberOfTransactions;
        long int previousBlock;
        String generatorPublicKey;
        String blockSignature;

				TransportPeerHeader();
				TransportPeerHeader(long int, long int, long double, long double, long double, long double, String, int, long int, long int, long int, String, String);
    
		}; 

};


ARK::TransportPeerHeader::TransportPeerHeader() {
  height = 0;
  version = 0.0;
  totalAmount = 0.0;
  totalFee = 0.0;
  reward = 0.0;
  payloadHash = "";
  payloadLength = 0;
  timestamp = 0;
  numberOfTransactions = 0;
  previousBlock = 0;
  generatorPublicKey = "";
  blockSignature = "";
}

ARK::TransportPeerHeader::TransportPeerHeader(
	long int _id,
	long int _height,
	long double _version,
	long double _totalAmount,
	long double _totalFee,
	long double _reward,
	String _payloadHash,
	int _payloadLength,
	long int _timestamp,
	long int _numberOfTransactions,
	long int _previousBlock,
	String _generatorPublicKey,
	String _blockSignature) :
		id(_id),
		height(_height),
		version(_version),
		totalAmount(_totalAmount),
		totalFee(_totalFee),
		reward(_reward),
		payloadHash(_payloadHash),
		payloadLength(_payloadLength),
		timestamp(_timestamp),
		numberOfTransactions(_numberOfTransactions),
		previousBlock(_previousBlock),
		generatorPublicKey(_generatorPublicKey),
		blockSignature(_blockSignature) {}


#endif
