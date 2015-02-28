// Alexeo Smith
// 04/01/2014
// Lab 8

#include "Account.h"

// Prevent multiple includes of this class
#ifndef CERTIFICATEOFDEPOSIT_H
#define CERTIFICATEOFDEPOSIT_H



class CertificateOfDeposit: public Account  //Inherits from account
{

	bool withDrawalExecuted;
public:
	CertificateOfDeposit(int acctNum)  //A constructor that takes in an account number as a parameter 
	{
		accountNum = acctNum;
		type = "Certificate of Deposit";
		withDrawalExecuted = false;
	}


	void withdrawal(double withdrawal)  //withdrawal
	{
				balance -= withdrawal;
				withDrawalExecuted = true;  //Keep track of withdrawals
	}


	void accrueInterest()
	{
		if(withDrawalExecuted)
			balance *= 1.01;		//Gained 1% interest if they made a withdrawal
		balance *= 1.10;			//Gained 10% interest if no withdrawal made

	}

};

#endif
