// Alexeo Smith
// 04/01/2014
// Lab 8

#include "Account.h"

// Prevent multiple includes of this class
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class SavingsAccount : public Account  //Inherits from account
{
public:
	SavingsAccount(int acctNum)  //A constructor that takes in an account number as a parameter 
	{
		accountNum = acctNum;
		type = "Savings";
	}


	void accrueInterest()
	{
		if(balance >= 100 && balance <=999.99)
			balance *= 1.01;
		else if (balance > 1000)
			balance *= 1.02;
	}


};

#endif
