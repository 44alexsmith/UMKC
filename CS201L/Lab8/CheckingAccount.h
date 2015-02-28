// Alexeo Smith
// 04/01/2014
// Lab 6

#include "Account.h"

// Prevent multiple includes of this class
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

class CheckingAccount : public Account  //Inherits from account
{
public:
	CheckingAccount(int acctNum)
	{
		accountNum = acctNum;
		type = "Checking";
	}

	void accrueInterest()  //Doesn't accrue any interest
	{
		balance = balance;
	}

};

#endif
