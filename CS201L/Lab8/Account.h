// Alexeo Smith
// 04/01/2014
// Lab 8

#include <string>
using namespace std;

// Prevent multiple includes of this class
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
	protected:
		//Member variables
		int accountNum;
		double balance;
		string type;


	public:
	
		Account() //Default constructor
		{
			balance = 0;
		}

		string getAccountType() //Returns the account type
		{
			return type;
		}

		double getBalance() //Returns the balance
		{
			return balance;
		}

		void deposit(double deposit)  //Deposit
		{
			balance += deposit;
		}

		void withdrawal(double withdrawal)  //withdrawal
		{
			balance -= withdrawal;
		}

		int getAccountNum()
		{
			return accountNum;
		}
		
		virtual void accrueInterest() = 0;  //Pure virtual function


};

#endif
