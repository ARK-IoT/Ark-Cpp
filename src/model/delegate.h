

#ifndef delegate_h
#define delegate_h


namespace ARK {

	class Delegate {
		public:
			String username;
			String address;
			String publicKey;
			String vote;
			long int producedblocks;
			long int missedblocks;
			long int rate;
			double approval;
			double productivity;


			String getDescription() {
				String resp;
				resp += "username: ";
						resp += this->username;
						resp += "\n";
				resp += "address: ";
						resp += this->address;
						resp += "\n";
				resp += "publicKey: ";
						resp += this->publicKey;
						resp += "\n";
				resp += "vote: ";
						resp += this->vote;
						resp += "\n";
				resp += "producedblocks: ";
						resp += this->producedblocks;
						resp += "\n";
				resp += "missedblocks: ";
						resp += this->missedblocks;
						resp += "\n";
				resp += "rate: ";
						resp += this->rate;
						resp += "\n";
				resp += "approval: ";
						resp += this->approval;
						resp += "%\n";
				resp += "productivity: ";
						resp += this->productivity;
						resp += "%\n";
				return resp;
			};

	};

};

#endif
