// Alexeo Smith
// 03/04/2014
// Lab 6

#include "LibraryBook.h"
#include "Patron.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// Create the variables
	ifstream finPatrons("patrons.txt");
	ifstream finCheckouts("checkouts.txt");
	ofstream fout("output.txt");

	// Patron info
	// Start with an array of 100 items
	Patron* patrons[100];
	int numPatrons = 0;
	string firstName;
	string lastName;
	int librarycard;
	// Book info for checking out
	string title;
	string author;
	int isbn;
	int patronNum;
	

	// Check if the files opened ok
	if(!finPatrons)
	{
		cout << "Can't open the patrons file!" << endl;
		system("pause");
		exit(1);
	}
	if(!finCheckouts)
	{
		cout << "Can't open the check in/outfile!" << endl;
		system("pause");
		exit(1);
	}

	// Read in Patrons into an array
	while (finPatrons >> librarycard >> firstName >> lastName)
	{
        // TODO: Implement this
		patrons[numPatrons] = new Patron(firstName,lastName,librarycard);
		numPatrons++;
		
	}

	// Read in books and store them in the Patron's book list
	while(finCheckouts >> patronNum >> isbn >> title >> author)
	{
        // TODO: Implement this
		for(int i =0; i<numPatrons; i++)
		{
			if(patrons[i]->getCardNumber() == patronNum)
				patrons[i]->checkOut(new LibraryBook(title, author, isbn));
		}

	}

	// Start report
	fout << "Books currently checked out" << endl << "---------------------------" << endl;

	// For all patrons, print out their list of books
	for(int i = 0; i < numPatrons; i++)
	{

        // Loop through the books
		for(int j=0; j<patrons[i]->getNumBooks(); j++)
		{ 
			fout << patrons[i]->getName() << " " << endl;
			fout << patrons[i]->getNumBooks() << " " << patrons[i]->getCardNumber() << " " << patrons[i]->getBook(j).getTitle() << endl;
		}
		
    }
	
}