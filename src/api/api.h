

#ifndef api_h
#define api_h

#include "api_model.h"

namespace ARK {
  namespace API {


		class Manager {
			public:

				ARK::Model::Network network;
				bool isConnected = false;

				Manager(ARK::Model::Network _network) {
					network = _network;
					isConnected = true;
				};

				bool disconnect() {
					if (!isConnected) {
						printf("Manager already disconnected from network");
						return false;
					}
					network = ARK::Model::Network();
					this->isConnected = false;
					return !this->isConnected;
				};

		};
		

	};
};

#endif


/*
Manager(ARK::Model::Network _network) {
	if (connect(_network) && this->network.nethash == _network.nethash)
		printf("Manager connected");
};

bool connect(ARK::Model::Network _network) {
	network = _network;
	isConnected = true;
	printf("Manager connected to network");
	return this->isConnected;
};

bool disconnect() {
	if (!isConnected) {
		printf("Manager already disconnected from network");
		return false;
	}
	network = ARK::Model::Network();
	isConnected = false;
	return !this->isConnected;
};

*/