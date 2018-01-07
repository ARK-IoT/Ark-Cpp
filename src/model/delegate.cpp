

#include "delegate.h"

ARK::Delegate::Delegate() {
  username("");
  address("");
  publicKey("");
  vote("");
  producedblocks(0);
  missedblocks(0);
  rate(0);
  approval(0.00);
  productivity(0.00);
}

ARK::Delegate::Delegate() :
  username(_username)
  address(_address)
  publicKey(_publicKey)
  vote(_vote)
  producedblocks(_producedblocks)
  missedblocks(_missedblocks)
  rate(_rate)
  approval(_approval)
  productivity(_productivity) {}

