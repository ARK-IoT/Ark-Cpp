#include "transaction.h"

#include <cstring>
#include <cstdio>

namespace ARK {

Transaction::Transaction(
    const char* const i,
    const char* const b,
    const char* const h,
    int t,
    const char* const ts,
    const char* const a,
    const char* const f,
    const char* const vf,
    const char* const si,
    const char* const ri,
    const char* const spk,
    const char* const s,
    const char* const c
) :
    id_(),
    blockid_(),
    height_(),
    type_(t),
    timestamp_(),
    amount_(a),
    fee_(f),
    vendorField_(),
    senderId_(si),
    recipientId_(ri),
    senderPublicKey_(spk),
    signature_(),
    confirmations_()
{
    strncpy(id_, i, sizeof(id_) / sizeof(id_[0]));
    strncpy(blockid_, b, sizeof(blockid_) / sizeof(blockid_[0]));
    strncpy(height_, h, sizeof(height_) / sizeof(height_[0]));
    strncpy(timestamp_, ts, sizeof(timestamp_) / sizeof(timestamp_[0]));
    strncpy(vendorField_, vf, sizeof(vendorField_) / sizeof(vendorField_[0]));
    strncpy(signature_, s, sizeof(signature_) / sizeof(signature_[0]));
    strncpy(confirmations_, c, sizeof(confirmations_) / sizeof(confirmations_[0]));
}


/*  ==========================================================================  */
/*  ================  */
/*  ARK::Transaction  */
/*  Description  */
void ARK::Transaction::Transaction::description(char* const buf, size_t /*size*/) {
	strcpy(buf, "id: ");
	strcat(buf, this->id_);
	strcat(buf, "\nblockid: ");
	strcat(buf, this->blockid_);
	strcat(buf, "\nheight: ");
	strcat(buf, this->height_);
	strcat(buf, "\ntype: ");
	sprintf(buf, "%d", this->type_);
	strcat(buf, "\ntimestamp: ");
	strcat(buf, this->timestamp_);
	strcat(buf, "\namount.ark: ");
	strcat(buf, this->amount_.ark());
	strcat(buf, "\nfee.ark: ");
	strcat(buf, this->fee_.ark());
	strcat(buf, "\nvendorField: ");
	strcat(buf, this->vendorField_);
	strcat(buf, "\nsenderId.description: ");
	strcat(buf, this->senderId_.description());
	strcat(buf, "\nrecipientId.description: ");
	strcat(buf, this->recipientId_.description());
	strcat(buf, "\nsenderPublicKey.description: ");
	strcat(buf, this->senderPublicKey_.description());
	strcat(buf, "\nsignature: ");
	strcat(buf, this->signature_);
	//strcat(buf, "\nasset: ");
	//strcat(buf, this->asset);
	strcat(buf, "\nconfirmations: ");
	strcat(buf, this->confirmations_);
}
/*  ================  */
/*  ==========================================================================  */


}
