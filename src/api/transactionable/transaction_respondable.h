

// #ifndef TRANSACTION_RESPONDABLE_H
// #define TRANSACTION_RESPONDABLE_H

// namespace ARK
// {
// namespace API
// {
// namespace Transaction
// {
// namespace Respondable
// {

// /*  ==========================================================================  */
// /*  ===============================================  */
// /*  ARK::API::Transaction::Respondable::Unconfirmed  */
// struct Unconfirmed {
//   public:

//     int count = 0;
//     ARK::Transaction list[10];

//     Unconfirmed(int);

//     String description();
// };
// /*  ===============================================  */
// /*  ==========================================================================  */

// };
// };
// };
// };




// /*  ==========================================================================  */
// /*  ===============================================  */
// /*  ARK::API::Transaction::Respondable::Unconfirmed  */
// ARK::API::Transaction::Respondable::Unconfirmed::Unconfirmed(int count) {
//   this->count = count;
// };
// /*  ===============================================  */
// String ARK::API::Transaction::Respondable::Unconfirmed::description() {
//   String resp;
//   if (this->count > 0) {
//     for (int i = 0; i < this->count; i++) {
//       resp += "\ntransaction ";
//       resp += i + 1;
//       resp += ":\n";
//       resp += this->list[i].description();
//       resp += "\n";
//     };
//   } else { resp += "There are currently no Unconfirmed Transactions"; };
//   return resp;
// };
// /*  ===============================================  */
// /*  ==========================================================================  */



// #endif