

#include "transport.h"

ARK::Transport() {
  height(0);
  version(0.0);
  totalAmount(0.0);
  totalFee(0.0);
  reward(0.0);
  payloadHash("");
  payloadLength(0);
  timestamp(0);
  numberOfTransactions(0);
  previousBlock(0);
  generatorPublicKey("");
  blockSignature("");
}

ARK::Transport() :
  height(_height)
  version(_version)
  totalAmount(_totalAmount)
  totalFee(_totalFee)
  reward(_reward)
  payloadHash(_payloadHash)
  payloadLength(_payloadLength)
  timestamp(_timestamp)
  numberOfTransactions(_numberOfTransactions)
  previousBlock(_previousBlock)
  generatorPublicKey(_generatorPublicKey)
  blockSignature(_blockSignature) {}

