

#ifndef BALANCE_H
#define BALANCE_H

/********************************************************************************
*
* Currently very verbose, needs bigint implementation using pow(10,8)
*
* Balance: 
*   arktoshi : "100000000"
*   ark : "1.00000000"
*   
*   Big Integer/Floating Point | 8-decimal places/pow(10,8)
*   
*   Currenty Block Supply total ~ 1.3e16 (12984403000000000:arktoshi)/(129844030.00000000:ark)
*
********************************************************************************/

/*************************************************
*   Balance
**************************************************/
struct Balance
{
	private:
    static const auto ARKTOSHI_SIZE = 17 * sizeof(int);
    static const auto ARK_SIZE = ((17 * sizeof(char)) + sizeof(int));
    static const auto DECIMAL_PLACES = 8u;

    char arktoshi_[ARKTOSHI_SIZE] = { '\0' };
    char ark_[ARK_SIZE] = { '\0' };

		void setArktoshi(const char* const balanceStr);
		void setArk(const char* const balanceStr);
		void setBalance(const char* const _balanceStr);

	public:
		
		Balance();
		explicit Balance(const char* const balanceStr);
		Balance(const Balance& other);

		Balance(Balance&& other);
		Balance& operator=(const Balance& other);
		Balance& operator=(Balance&& other);

    const char* ark() const;
    const char* arktoshi() const;

};

#endif
