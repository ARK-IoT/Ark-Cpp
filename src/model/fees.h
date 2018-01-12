

#ifndef fees_h
#define fees_h

namespace ARK {
		struct Fees {
			int send;
			int vote;
			int delegate;
			int secondsignature;
			int multisignature;

      Fees();
      Fees(int, int, int, int, int);

      String description();

		};
};


ARK::Fees::Fees() {
  send = 0;
  vote = 0;
  delegate = 0;
  secondsignature = 0;
  multisignature = 0;
}

ARK::Fees::Fees(
  int _send,
  int _vote,
  int _delegate,
  int _secondsignature,
  int _multisignature) :
    send(_send),
    vote(_vote),
    delegate(_delegate),
    secondsignature(_secondsignature),
    multisignature(_multisignature) {}


String ARK::Fees::Fees::description() {
  String resp;
  resp += "send: ";
      resp += this->send;
      resp += "\n";
  resp += "vote: ";
      resp += this->vote;
      resp += "\n";
  resp += "delegate: ";
      resp += this->delegate;
      resp += "\n";
  resp += "secondsignature: ";
      resp += this->secondsignature;
      resp += "\n";
  resp += "multisignature: ";
      resp += this->multisignature;
      resp += "\n";
  return resp;
}



#endif
