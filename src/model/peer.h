

#ifndef peer_h
#define peer_h

namespace ARK
{

	/*************************************************
	*   ARK::peer_t
	**************************************************/
	struct peer_t
	{
		public:
			char ip[40];
			int port;
			char version[32];
			int errors;
			char os[32];
			char height[32];
			char status[32];
			int delay;
	};
	/*************************************************/


	/*************************************************
	*   ARK::Peer
	**************************************************/
	struct Peer :
			public peer_t
	{
		Peer(
				const char* const newIP,
				int newPort,
				const char* const newVersion,
				int newErrors,
				const char* const newOS,
				const char* const newHeight,
				const char* const newStatus,
				int newDelay
		)
		{
			strncpy( ip, newIP, sizeof(ip) / sizeof(ip[0]) );
			port = newPort;
			strncpy( version, newVersion, sizeof(version) / sizeof(version[0]) );
			errors = newErrors;
			strncpy( os, newOS, sizeof(os) / sizeof(os[0]) );
			strncpy( height, newHeight, sizeof(height) / sizeof(height[0]) );
			strncpy( status, newStatus, sizeof(status) / sizeof(status[0]) );
			delay = newDelay;
		};

		void printTo(HardwareSerial &serial);
	};
	/*************************************************/

};


/*************************************************
*	ARK::Peer
*
*   @methods:	printTo(HardwareSerial &serial)
*
*   @description:
*     Prints Peer Model information to Serial
*
**************************************************/
void ARK::Peer::printTo(HardwareSerial &serial)
{
	serial.print("\nip: ");
		serial.print(this->ip);
	serial.print("\nport: ");
		serial.print(this->port);
	serial.print("\nversion: ");
		serial.print(this->version);
	serial.print("\nerrors: ");
		serial.print(this->errors);
	serial.print("\nos: ");
		serial.print(this->os);
	serial.print("\nheight: ");
		serial.print(this->height);
	serial.print("\nstatus: ");
		serial.print(this->status);
	serial.print("\ndelay: ");
		serial.print(this->delay);
	serial.print("\n");
	serial.flush();
}
/*************************************************/


#endif
