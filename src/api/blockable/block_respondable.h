

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
	*	ARK::API::Block::Respondable::height_t 
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
	struct height_t
	{
		public:
			char height[64];
			char id[64];
	};
	/*************************************************/

	/*************************************************
	*	ARK::API::Block::Respondable::Height 
	*
	*   @inherits:
	*			const char* height
	*			const char* id
	*
	*   @methods:	printTo(HardwareSerial &serial)
	*
	*   @description:
	*			Model for Height API Response
	*
	**************************************************/
	struct Height : public height_t
	{
    Height(
			const char* const newHeight,
			const char* const newID
		)
		{ 
        strncpy(height, newHeight, sizeof(height) / sizeof(height[0]));
        strncpy(id, newID, sizeof(id) / sizeof(id[0]));
    }

			void printTo(HardwareSerial &serial);
	};
	/*************************************************/


	/**************************************************************************************************/


	/*************************************************
	*	ARK::API::Block::Respondable::status_t 
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
	*   @description:
	*			Model for Block Status API Response
	*
	**************************************************/
	struct status_t
	{
		public:
    	char epoch[64];  //TODO: check sizes
    	char height[64];
			Balance fee;
			int milestone;
			Hash nethash;
			Balance reward;
			Balance supply;
	};
	/*************************************************/


	/*************************************************
	*	ARK::API::Block::Respondable::Status 
	*
	*		@inherits:
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
	*			Constructor Model for Block Status API Response
	*
	**************************************************/
	struct Status : public status_t
	{

    Status(
        const char* const newEpoch, 
        const char* const newHeight,
        const char* const newFee,
        int newMilestone,
        const char* const newNethash,
        const char* const newReward,
        const char* const newSupply
    )
    {
			strncpy(epoch, newEpoch, sizeof(epoch) / sizeof(epoch[0]));
			strncpy(height, newHeight, sizeof(height) / sizeof(height[0]));
			fee = Balance(newFee);
			milestone = newMilestone;
			nethash = Hash(newNethash);
			reward = Balance(newReward);
			supply = Balance(newSupply);
    }

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
	serial.print(this->nethash.getValue());
	serial.print("\nreward: ");
	serial.print(this->reward.ark());
	serial.print("\nsupply: ");
	serial.print(this->supply.ark());
	serial.print("\n");
	serial.flush();
}
/*************************************************/


#endif