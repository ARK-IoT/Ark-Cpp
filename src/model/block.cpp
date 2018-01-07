

#include "block.h"

ARK::Block() {
  id(0) 
  version(0.0.0);
  timestamp(0);
  heigh(0);
  previousBlock(0);
  numberOfTransactions(0);
  totalAmount(0.0);
  totalFee(0.0);
  reward(0);
  intpayloadLength(0);
  payloadHash("");
  generatorPublicKey("");
  generatorId("");
  blockSignature("");
  confirmations(0)
  totalForged(0);
}

ARK::Block() :
  id(_id)
  version(_version)
  timestamp(_timestamp)
  heigh(_heigh)
  previousBlock(_previousBlock)
  numberOfTransactions(_numberOfTransactions)
  totalAmount(_totalAmount)
  totalFee(_totalFee)
  reward(_reward)
  intpayloadLength(_intpayloadLength)
  payloadHash(_payloadHash)
  generatorPublicKey(_generatorPublicKey
  generatorId(_generatorId)
  blockSignature(_blockSignature)
  confirmations(_confirmations)
  totalForged(_totalForged) {}


