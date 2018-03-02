

#ifndef DELEGATE_RESPONDABLE_H
#define DELEGATE_RESPONDABLE_H

namespace ARK
{
namespace API
{
namespace Delegate
{
namespace Respondable
{
/*************************************************
*		ARK::API::Delegate::Respondable::search_t
*
*		@param: char[20], Address, Publickey, Balance, int, int
*
*   @brief:	Model for Delegate Search API Response
*
**************************************************/
struct search_t
{
	public:
    char username[20];
    Address address;
    Publickey publicKey;
    Balance vote;
    int producedblocks;
    int missedblocks;
};
/*************************************************/


/*************************************************
*		ARK::API::Delegate::Respondable::Search
*
*		inherits:
*			const char* username;
*			Address address;
*			Publickey publicKey;
*			const Balance vote;
*			int producedblocks;
*			int missedblocks;
*
*   printTo(HardwareSerial &serial)
*
*   @brief:	Model for Delegate Search API Response
**************************************************/
struct Search :
		public search_t, Printable
{
	public:

		Search(
				const char* const newUsername,
				const char* const newAddress,
				const char* const newPublickey,
				const char* const newVote,
				int newProducedBlocks,
				int newMissedBlocks
		)
		{
			strncpy(username, newUsername, sizeof(username) / sizeof(username[0]));
			address = Address(newAddress);
			publicKey = Publickey(newPublickey);
			vote = Balance(newVote);
			producedblocks = newProducedBlocks;
			missedblocks = newMissedBlocks;
		};

		virtual size_t printTo(Print& p) const
		{
			size_t size = 0;
				size += p.print("\nusername: ");
				size += p.print(this->username);

				size += p.print("\naddress: ");
				size += p.print(this->address);

				size += p.print("\npublicKey: ");
				size += p.print(this->publicKey);

				size += p.print("\nvote: ");
				size += p.print(this->vote.ark());

				size += p.print("\nproducedblocks: ");
				size += p.print(this->producedblocks);

				size += p.print("\nmissedblocks: ");
				size += p.print(this->missedblocks);
			return size;
		};
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*		ARK::API::Delegate::Respondable::Voters
*
*		@param:	size_t, ARK::Voter* const
*
*   printTo(HardwareSerial &serial)
*		deconstuctor:	~Voters() { delete [] _voters; };
*		operators: 
*			Voter& operator[](size_t index)
*			Voter& operator[](size_t index)
*
*   @brief:	Model for Delegate Voters API Response
*
**************************************************/
struct Voters :
		public Printable
{
	public:
    size_t count;
    ARK::Voter* const voters;

    Voters(size_t c) : count(c), voters(new ARK::Voter[c]) {}

    ~Voters() { delete [] voters; }

    const Voter& operator[](size_t index) const { return voters[index]; }
    Voter& operator[](size_t index) { return voters[index]; }

    virtual size_t printTo(Print& p) const
		{
			size_t size = 0;

			if (this->count > 0)
			{
				size += p.print("\n\0");

				for (int i = 0; i < static_cast<int>(this->count); i++)
				{
					size += p.print("\nvoter ");
					size += p.print(i + 1);
					size += p.print(":\n");
					size += p.print(voters[i]);
					size += p.print("\n");
				};
			};
			return size;
		}
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*		ARK::API::Delegate::Respondable::forged_by_account_t
*
*		@param:	const Balance, const Balance, const Balance;
*
*   @description:
*			Model for Delegate Forging Totals API Response
*
**************************************************/
struct forged_by_account_t
{
	public:
    Balance fees;
    Balance rewards;
    Balance forged;
};
/*************************************************/


/*************************************************
*		ARK::API::Delegate::Respondable::ForgedByAccount
*
*		inherits: Balance fees, Balance rewards, Balance forged;
*
*   printTo(HardwareSerial &serial)
*
*   @brief: Model for Delegate Forging Totals API Response
**************************************************/
struct ForgedByAccount :
		public forged_by_account_t, Printable
{
	public:

		ForgedByAccount(
				const char* const newFees,
				const char* const newRewards,
				const char* const newForged
		)
		{
			this->fees = Balance(newFees);
			this->rewards = Balance(newRewards);
			this->forged = Balance(newForged);
		};

		virtual size_t printTo(Print& p) const
		{
			size_t size = 0;
				size += p.print("fees: ");
				size += p.print(this->fees.ark());
				size += p.print("\nrewards: ");
				size += p.print(this->rewards.ark());
				size += p.print("\nforged: ");
				size += p.print(this->forged.ark());
			return size;
		};

};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*		ARK::API::Delegate::Respondable::next_forgers_t
*
*		@param: char currentBlock[64], char currentSlot[64], Publickey* const
*
*   @brief:	Model for Next 10 Forging Delegate Publickeys API Response
**************************************************/
struct next_forgers_t
{
	public:
		char currentBlock[64];
		char currentSlot[64];
		Publickey* const delegateKeys = new Publickey[10];
};
/*************************************************/


/*************************************************
*		ARK::API::Delegate::Respondable::NextForgers
*
*		inherits: char[64], char[64], Publickey* const
*
*   printTo(HardwareSerial &serial)
*
*   @brief:	Model for Next 10 Forging Delegate Publickeys API Response
**************************************************/
struct NextForgers :
		public next_forgers_t, Printable
{
	public:

		NextForgers
		(
				const char* const newCB,
				const char* const newCS,
				const Publickey* const newDelegateKeys
		)
		{
			strncpy(this->currentBlock, newCB, sizeof(this->currentBlock));
			strncpy(this->currentSlot, newCS, sizeof(this->currentSlot));
			for (auto i = 0; i < 10; ++i)
			{
				this->delegateKeys[i] = newDelegateKeys[i];
			};
		}

		virtual size_t printTo(Print& p) const
		{
			size_t size = 0;
				size += p.print("currentBlock: ");
				size += p.print(this->currentBlock);
				size += p.print("\ncurrentSlot: ");
				size += p.print(this->currentSlot);

			for (int i = 0; i < 9; i++)
			{
				size += p.print("delegate ");
				size += p.print(i + 1);
				size += p.print(":\npublicKey: ");
				size += p.print(delegateKeys[i]);
			};
			return size;
		};
};
/*************************************************/

};
};
};
};

#endif
