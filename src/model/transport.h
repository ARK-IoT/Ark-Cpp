

#ifndef transport_h
#define transport_h

namespace ARK {
    
	/*  ========================  */
	/*  ARK::TransportPeerHeader  */
    struct TransportPeerHeader {
      public:
        String id;
        String height;
        int version;
        Balance totalAmount;
        Balance totalFee;
        Balance reward;
        Hash payloadHash;
        int payloadLength;
        String timestamp;
        int numberOfTransactions;
        String previousBlock;
        Publickey generatorPublicKey;
        Signature blockSignature;

				// TransportPeerHeader();
				// TransportPeerHeader(String, String, int, Balance, Balance, Balance, Hash, int, String, int, String, Publickey, Signature);
    
		}; 
	/*  ========================  */

};




/*  ========================  */
/*  ARK::TransportPeerHeader  */

/*  Constructor  */
// ARK::TransportPeerHeader::TransportPeerHeader() {
// 	id = "";
//   height = "";
//   version = 0;
//   totalAmount = { "0" };
//   totalFee = { "0" };
//   reward = { "0" };
//   payloadHash = { "" };
//   payloadLength = 0;
//   timestamp = "";
//   numberOfTransactions = 0;
//   previousBlock = "";
//   generatorPublicKey = { "" };
//   blockSignature = { "" };
// }

/*  =====  */

/*  Constructor  */
// ARK::TransportPeerHeader::TransportPeerHeader(
// 	String _id,
// 	String _height,
// 	int _version,
// 	Balance _totalAmount,
// 	Balance _totalFee,
// 	Balance _reward,
// 	Hash _payloadHash,
// 	int _payloadLength,
// 	String _timestamp,
// 	int _numberOfTransactions,
// 	String _previousBlock,
// 	Publickey _generatorPublicKey,
// 	Signature _blockSignature) :
// 		id(_id),
// 		height(_height),
// 		version(_version),
// 		totalAmount(_totalAmount),
// 		totalFee(_totalFee),
// 		reward(_reward),
// 		payloadHash(_payloadHash),
// 		payloadLength(_payloadLength),
// 		timestamp(_timestamp),
// 		numberOfTransactions(_numberOfTransactions),
// 		previousBlock(_previousBlock),
// 		generatorPublicKey(_generatorPublicKey),
// 		blockSignature(_blockSignature) {}
/*  ========================  */


#endif
