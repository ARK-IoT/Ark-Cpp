

#ifndef api_h
#define api_h

#include "api_model.h"

namespace ARK {
  namespace API {


		class Manager {
			public:
				ARK::Model::Network network;
				bool connected = false;
				Manager();
		};
		

	};
};

#endif

/*
Manager(ARK::Model::Network _network) {
	connect(_network);
};
bool connect(ARK::Model::Network _network) {
	if (ARK::Model::isValid(_network)) {
		network = _network;
		connected = true;
	}
	return connected;
};
bool disconnect() {
	if (connected) {
		network = ARK::Model::Network();
		connected = false;
	}
	return !connected;
};
*/