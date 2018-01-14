

#ifndef fees_h
#define fees_h

namespace ARK {

		// bigints
		struct Fees {
			String send;
			String vote;
			String delegate;
			String secondsignature;
			String multisignature;

			Fees();
			Fees(String, String, String, String, String);

			String description();

		};
};


ARK::Fees::Fees() {
  send = "";
  vote = "";
  delegate = "";
  secondsignature = "";
  multisignature = "";
}

ARK::Fees::Fees(
  String _send,
  String _vote,
  String _delegate,
  String _secondsignature,
  String _multisignature) :
    send(_send),
    vote(_vote),
    delegate(_delegate),
    secondsignature(_secondsignature),
    multisignature(_multisignature) {}


String ARK::Fees::Fees::description() {
  String resp;
  resp += "send: ";
      resp += this->send; resp += "\n";
  resp += "vote: ";
      resp += this->vote; resp += "\n";
  resp += "delegate: ";
      resp += this->delegate; resp += "\n";
  resp += "secondsignature: ";
      resp += this->secondsignature; resp += "\n";
  resp += "multisignature: ";
      resp += this->multisignature;
  return resp;
}



#endif
