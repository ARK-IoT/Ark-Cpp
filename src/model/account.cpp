

#include "account.h"

ARK::Delegate::Delegate() {
  address("");
  unconfirmedBalance("");
  balance("");
  publicKey("");
  unconfirmedSignature(0);
  secondSignature(0);
  secondPublicKey("");
  multisignatures("");
  u_multisignatures("");
}

ARK::Account() :
  address(_address)
  unconfirmedBalance(_unconfirmedBalance)
  balance(_balance)
  publicKey(_publicKey)
  unconfirmedSignature(_unconfirmedSignature)
  secondSignature(_secondSignature)
  secondPublicKey(_secondPublicKey)
  multisignatures(_multisignatures)
  u_multisignatures(_u_multisignatures) {}

