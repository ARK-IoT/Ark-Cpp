#include "account.h"

/*  ================================================  */
/*  ============  */
/*  Description  */
void ARK::Account::Account::description(char* const buf, size_t /*len*/)
{
	//TODO:  check len for sufficient size  
	strcpy(buf, "address: ");
	strcat(buf, address_.description());
	strcat(buf, "\nunconfirmedBalance.ark: ");
	strcat(buf, this->unconfirmedBalance_.ark());
	strcat(buf, "\nbalance.ark: ");
	strcat(buf, this->balance_.ark());
	strcat(buf, "\npublicKey.description: ");
	strcat(buf, this->publicKey_.description());
	strcat(buf, "\nunconfirmedSignature: ");
	sprintf(buf + strlen(buf), "%d", this->unconfirmedSignature_);
	strcat(buf, "\nsecondSignature: ");
	sprintf(buf + strlen(buf), "%d", this->secondSignature_);
	strcat(buf, "\nsecondPublicKey.description: ");
	strcat(buf, this->secondPublicKey_.description());
	strcat(buf, "\nmultisignatures.description: ");
	strcat(buf, this->multisignatures_.description());
	strcat(buf, "\nu_multisignatures.description: ");
	strcat(buf, this->u_multisignatures_.description());
}
/*  ============  */
/*  ================================================  */
