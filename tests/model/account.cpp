#include "account.h"

void construct_account() {
    ARK::Account account(
        "DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA",
        "100000000",//Balance("100000000"),
        "100000000", //Balance("100000000"),
        "0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", //Publickey("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456"),
        0,
        0,
        "", //Publickey(),
        "", //Signature(),
        "" //Signature()
    );
}