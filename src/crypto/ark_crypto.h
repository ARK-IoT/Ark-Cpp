#ifndef ARK_CRYPTO_H
#define ARK_CRYPTO_H

#include "constants/constants.h"
#include "models/account.h"
#include "Uint256.hpp"
#include "Sha256Hash.hpp"

#include <string>
#include <vector>

namespace ARK {

class Transaction;

namespace Crypto {

void get_keys(const char* const passphrase, uint8_t priv_key[PRIVATE_KEY_SIZE], std::vector<uint8_t>& pub_key, bool compressed = true);
void get_private_key(const char* const passphrase, uint8_t priv_key[PRIVATE_KEY_SIZE]);
void get_public_key(const uint8_t priv_key[PRIVATE_KEY_SIZE], std::vector<uint8_t>& pub_key, bool compressed = true);
std::string to_wif(uint8_t version, const uint8_t key[PRIVATE_KEY_SIZE], bool compressed = true);
void from_wif(const std::string& wif, uint8_t& version, uint8_t priv_key[PRIVATE_KEY_SIZE], bool& compressed);
void toDER(uint8_t packed_signature[PRIVATE_KEY_SIZE * 2], std::vector<uint8_t>& signature);
void toDER(const std::vector<uint8_t>& r, const std::vector<uint8_t>& s, std::vector<uint8_t>& signature);
std::vector<uint8_t>& convert_to_der_buffer(std::vector<uint8_t>& buffer);
void sign(const Sha256Hash& hash, const uint8_t priv_key[PRIVATE_KEY_SIZE], std::vector<uint8_t>& signature);
std::string get_address(uint8_t network, const std::vector<uint8_t>& public_key);
bool validate_address(const char* const address, uint8_t network);
Account create_account(uint8_t network, const char* const passphrase);

ARK::Transaction create_transaction(uint8_t network, const char* const address, uint64_t amount_in_arktoshi, const std::string& vendor_field, uint8_t secret[PRIVATE_KEY_SIZE], uint8_t second_secret[PRIVATE_KEY_SIZE] = nullptr, uint32_t version = 1, uint64_t fee_override = ARK::send_fee);
void get_transaction_bytes(const ARK::Transaction& transaction, uint8_t buffer[512]);

}
}

#endif
