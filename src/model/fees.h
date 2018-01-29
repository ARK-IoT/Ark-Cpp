

#ifndef fees_h
#define fees_h

namespace ARK
{

/*  ================================================  */
/*  =========  */
/*  ARK::Fees  */
struct Fees
{
    Balance send;
    Balance vote;
    Balance delegate;
    Balance secondsignature;
    Balance multisignature;

    // Fees();
    // Fees(
    //     Balance,
    //     Balance,
    //     Balance,
    //     Balance,
    //     Balance);

    String description();
};
/*  =========  */
/*  ================================================  */

};

/*  ================================================  */
/*  =========  */
/*  ARK::Fees  */

// /*  Constructor  */
// ARK::Fees::Fees()
// {
//     send = {""};
//     vote = {""};
//     delegate = {""};
//     secondsignature = {""};
//     multisignature = {""};
// }

// /*  =====  */

// /*  Constructor  */
// ARK::Fees::Fees(
//     Balance _send,
//     Balance _vote,
//     Balance _delegate,
//     Balance _secondsignature,
//     Balance _multisignature) : send({_send}),
//                                vote({_vote}),
//                                delegate({_delegate}),
//                                secondsignature({_secondsignature}),
//                                multisignature({_multisignature}) {}

/*  =====  */
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
