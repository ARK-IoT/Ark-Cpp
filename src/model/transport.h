

#ifndef transport_h
#define transport_h

namespace ARK
{
  /*************************************************
  *	ARK::TransportPeerHeader
  **************************************************/
  struct TransportPeerHeader
  {
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
  }; 
  /*************************************************/

};


#endif
