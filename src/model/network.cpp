#include "network.h"

#include <cstdio>

/*  ================================================  */
/*  ============  */
/*  ARK::Delegate  */
/*  Description  */
void ARK::Network::Network::description(char* const buf, size_t /*size*/) const {
    strcpy(buf, "nethash: ");
    strcat(buf, this->nethash);
    strcat(buf, "\ntoken: ");
    strcat(buf, this->token);
    strcat(buf, "\nsymbol: ");
    strcat(buf, this->symbol);
    strcat(buf, "\nexplorer: ");
    strcat(buf, this->explorer);
    strcat(buf, "\nversion: ");
    const auto len = strlen(buf);
    sprintf(buf + len, "%d", this->version);
};
/*  =====  */
/*  Operator  */
/*  ARK::Network == ARK::Network  */
bool ARK::Network::Network::operator==(const Network& rhs) const {
    return (strcmp(this->nethash, rhs.nethash) == 0
        && strcmp(this->token, rhs.token) == 0
        && strcmp(this->symbol, rhs.symbol) == 0
        && strcmp(this->explorer, rhs.explorer) == 0
        && this->version == rhs.version);
};
/*  =====  */
/*  Operator  */
/*  ARK::Network != ARK::Network  */
bool ARK::Network::Network::operator!=(const Network& rhs) const { return !(*this == rhs); };
/*  ============  */
/*  ================================================  */

