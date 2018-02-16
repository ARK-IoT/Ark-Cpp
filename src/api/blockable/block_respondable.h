

#ifndef BLOCK_RESPONDABLE_H
#define BLOCK_RESPONDABLE_H

namespace ARK
{
namespace API
{
namespace Block
{
namespace Respondable
{

	/*************************************************
	*	ARK::API::Block::Respondable::Height 
	*
	*   @variables:
	*			const char* height
	*			const char* id
	*
	*   @methods:	printTo(HardwareSerial &serial)
	*
	*   @description:
	*			Model for Height API Response
	*
	**************************************************/
	struct Height
	{
		public:
			const char* height; 
			const char* id;

			void printTo(HardwareSerial &serial);
	};
	/*************************************************/


	/**************************************************************************************************/


	/*************************************************
	*	ARK::API::Block::Respondable::Status 
	*
	*		@variables:
	*			const char* epoch;
	*			const char* height;
	*			const Balance fee;
	*			int milestone;
	*			Hash nethash;
	*			const Balance reward;
	*			const Balance supply;
	*
	*   @methods:	printTo(HardwareSerial &serial)
	*
	*   @description:
	*			Model for Block Status API Response
	*
	**************************************************/
	struct Status
	{
		public:
			const char* epoch;
			const char* height;
			const Balance fee;
			int milestone;
			Hash nethash;
			const Balance reward;
			const Balance supply;

			void printTo(HardwareSerial &serial);
	};
	/*************************************************/


};
};
};
};


/*************************************************
*	ARK::API::Block::Respondable::Height
*
*   @methods:	printTo(HardwareSerial &serial)
*
*   @description:
*     Prints API Height Response to Serial
*
**************************************************/
void ARK::API::Block::Respondable::Height::printTo(HardwareSerial &serial)
{
	serial.print("\nheight: ");
	serial.print(this->height);
	serial.print("\nid: ");
	serial.print(this->id);
	serial.print("\n");
	serial.flush();
}
/*************************************************/


/**************************************************************************************************/


/*************************************************
*	ARK::API::Block::Respondable::Status
*
*   @methods:	printTo(HardwareSerial &serial)
*
*   @description:
*     Prints API Status Response to Serial
*
**************************************************/
void ARK::API::Block::Respondable::Status::printTo(HardwareSerial &serial)
{
	serial.print("\nepoch: ");
	serial.print(this->epoch);
	serial.print("\nheight: ");
	serial.print(this->height);
	serial.print("\nfee: ");
	serial.print(this->fee.ark());
	serial.print("\nmilestone: ");
	serial.print(this->milestone);
	serial.print("\nnethash: ");
	serial.print(this->nethash.value);
	serial.print("\nreward: ");
	serial.print(this->reward.ark());
	serial.print("\nsupply: ");
	serial.print(this->supply.ark());
	serial.print("\n");
	serial.flush();
}
/*************************************************/


#endif