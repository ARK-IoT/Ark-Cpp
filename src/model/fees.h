

#ifndef fees_h
#define fees_h

namespace ARK
{

/*************************************************
* ARK::Fees
*   /api/blocks/getFees
**************************************************/
struct Fees
{
    const Balance send;
    const Balance vote;
    const Balance delegate;
    const Balance secondsignature;
    const Balance multisignature;

    void printTo(HardwareSerial &serial);
};
/*************************************************/

};


/*************************************************
* ARK::Fees
*   printTo(Serial)
**************************************************/
void ARK::Fees::printTo(HardwareSerial &serial)
{
    serial.print("\nsend: ");
    serial.print(this->send.ark());
    serial.print("\nvote: ");
    serial.print(this->vote.ark());
    serial.print("\ndelegate: ");
    serial.print(this->delegate.ark());
    serial.print("\nsecondsignature: ");
    serial.print(this->secondsignature.ark());
    serial.print("\nmultisignature: ");
    serial.print(this->multisignature.ark());
    serial.print("\n");
    serial.flush();
}
/*************************************************/


#endif
