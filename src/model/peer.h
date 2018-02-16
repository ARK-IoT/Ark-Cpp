

#ifndef peer_h
#define peer_h

namespace ARK
{
	/*************************************************
	*   ARK::Peer
	**************************************************/
	struct Peer {
		public:
			const char* ip;
			int port;
			const char* version;
			int errors;
			const char* os;
			const char* height;
			const char* status;
			int delay;

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
