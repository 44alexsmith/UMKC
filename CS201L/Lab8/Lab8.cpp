// Alexeo Smith
// 04/01/2014
// Lab 8

#include "Account.h"
#include "CertificateOfDeposit.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <fstream>
#include <string>
using namespace std;

int main() 
{
	// File I/O
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	// Stores up to 30 accounts
	Account* accounts[30];
	// Number of accounts that have been opened
	int numAccounts = 0;

	// For file input processing
	string command, acctType;
	int acctNum1, acctNum2;
	double amount;

	// Do the input and math
	while(fin >> command)
	{
        // If the first word is NEW, create a new account based on data in the 
        // rest of the line
		if(command == "NEW")
		{
			   //Pointer to an account
			fin >> acctType;
			fin >> acctNum1;
			if(acctType == "CHECKING")
			{
				accounts[numAccounts] = new CheckingAccount(acctNum1);
				numAccounts++;
			}
			else if(acctType == "CERTIFICATE")
			{	
				accounts[numAccounts] = new CertificateOfDeposit(acctNum1);
				numAccounts++;
			}
			else if(acctType == "SAVINGS")
			{
				accounts[numAccounts] = new SavingsAccount(acctNum1);
				numAccounts++;
			}

        }
        // If the first word is WITHDRAWAL, remove money from the account using 
        // the data on the rest of the line
		else if (command == "WITHDRAWAL")
		{
			fin >> acctNum1;
			fin >> amount;
			for(int i = 0; i<numAccounts; i++)
			{
				if(accounts[i]->getAccountNum() == acctNum1)
					accounts[i]->withdrawal(amount);
			}

		
        }
        // If the first word is DEPOSIT, add money from the account using the 
        // data on the rest of the line
		else if (command == "DEPOSIT")
		{
			fin >> acctNum1;
			fin >> amount;
			for(int i = 0; i<numAccounts; i++)
			{
				if(accounts[i]->getAccountNum() == acctNum1)
					accounts[i]->deposit(amount);
			}
        }
        // If the first word is TRANSFER, move money between two accounts 
        // using data on the rest of the line
		else if (command == "TRANSFER")
		{
			fin >> acctNum1;
			fin >> acctNum2;
			fin >> amount;

			for(int i = 0; i<numAccounts; i++)
			{
				if(accounts[i]->getAccountNum() == acctNum2)
					accounts[i]->deposit(amount);
				if(accounts[i]->getAccountNum() == acctNum1)
					accounts[i]->withdrawal(amount);
			}


        }
        // If the first word is INTEREST, calculate interest on all accounts
		else if (command == "INTEREST")
		{
			for(int i = 0; i<numAccounts; i++)
				accounts[i]->accrueInterest();

        }
    }
	// Print output
	fout << "BANK STATEMENT" << endl << endl;

	// For every account, print out its data. Since they are all accounts with 
    // these same functions, we can get the data from any type of Account.
    for(int i = 0; i < numAccounts; i++)
	{
		fout << "Account number: " << accounts[i]->getAccountNum() << endl;
		fout << "Type of account: " << accounts[i]->getAccountType() << endl;
		fout << "Balance: $" << accounts[i]->getBalance() << endl;
		fout << endl;
	}

    // It is an array of pointers, so we need to delete them when we are done
	for (int i = 0; i < numAccounts; i++)
		delete accounts[i];

    // Close files
    fin.close();
    fout.close();
    return 0;
}