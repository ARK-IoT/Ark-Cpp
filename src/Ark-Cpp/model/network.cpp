#include "network.h"

#include <cstdio>

/*  ================================================  */
/*  ============  */
/*  ARK::Delegate  */
/*  Description  */
void ARK::Network::Network::description(char* const buf, size_t /*size*/) const {
    strcpy(buf, "nethash: ");
    strcat(buf, this->nethash_);
    strcat(buf, "\ntoken: ");
    strcat(buf, this->token_);
    strcat(buf, "\nsymbol: ");
    strcat(buf, this->symbol_);
    strcat(buf, "\nexplorer: ");
    strcat(buf, this->explorer_);
    strcat(buf, "\nversion: ");
    const auto len = strlen(buf);
    sprintf(buf + len, "%d", this->version_);
};
/*  =====  */
/*  Operator  */
/*  ARK::Network == ARK::Network  */
bool ARK::Network::Network::operator==(const Network& rhs) const {
    return (strcmp(this->nethash_, rhs.nethash_) == 0
        && strcmp(this->token_, rhs.token_) == 0
        && strcmp(this->symbol_, rhs.symbol_) == 0
        && strcmp(this->explorer_, rhs.explorer_) == 0
        && this->version_ == rhs.version_);
};
/*  =====  */
/*  Operator  */
/*  ARK::Network != ARK::Network  */
bool ARK::Network::Network::operator!=(const Network& rhs) const { return !(*this == rhs); };
/*  ============  */
/*  ================================================  */

