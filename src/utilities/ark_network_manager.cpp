

// #include "ark_network_manager.h"

//  ARK::Utilities::Network::Manager::Manager() {
//   this->network = ARK::Network();
//   this->networkPeer = "";
//   this->netType = ARK::NetworkType();
// }

// ARK::Utilities::Network::Manager::Manager(ARK::Network _network) : connect(_network) {
//   this->connect(_network);
// }

// ARK::Utilities::Network::Manager::connect(ARK::Network _network) {
//   if (_network.nethash == ARK::Constants::Networks::Devnet::nethash)
//     netType = ARK::NetworkType::DEV;
//   if (_network.nethash == ARK::Constants::Networks::Mainnet::nethash)
//     netType = ARK::NetworkType::MAIN;
//   this->network = _network;
//   this->setNetworkPeer(this->randomPeer());
//   this->isReachable = true;
// };