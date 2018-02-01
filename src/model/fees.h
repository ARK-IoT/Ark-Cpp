

#ifndef fees_h
#define fees_h

namespace ARK
{

/*  ================================================  */
/*  =========  */
/*  ARK::Fees  */
/*  /api/blocks/getFees */
struct Fees
{
    Balance send;
    Balance vote;
    Balance delegate;
    Balance secondsignature;
    Balance multisignature;

    String description();
};
/*  =========  */
/*  ================================================  */

};

/*  ================================================  */
/*  =========  */
/*  ARK::Fees  */
/*  Description  */
String ARK::Fees::Fees::description()
{
    String resp;
    resp += "send.ark: ";
    resp += this->send.ark;
    resp += "\n";
    resp += "vote.ark: ";
    resp += this->vote.ark;
    resp += "\n";
    resp += "delegate.ark: ";
    resp += this->delegate.ark;
    resp += "\n";
    resp += "secondsignature.ark: ";
    resp += this->secondsignature.ark;
    resp += "\n";
    resp += "multisignature.ark: ";
    resp += this->multisignature.ark;
    return resp;
}
/*  =========  */
/*  ================================================  */

#endif
