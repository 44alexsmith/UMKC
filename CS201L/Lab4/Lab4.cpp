// Alexeo Smith
// 2/18/2014
// Lab #4

#include "LibraryBook.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
	// File stream variables
    ifstream finBooks("books.txt");
	ifstream finISBN("isbns.txt");
	ofstream fout("checkedout.txt");

	//Hold value of the array
	int numberOfBooks = 0;

	// Check for file errors first
	if(!finBooks || !finISBN)
	{
		cout << "Error opening input files!\n";
		system("pause");
		return 1;
	}


    // Write program in here

	//Declare an array to hold the books
	LibraryBook myBook[10];

	

	//Read in the books from the input file
	while(finBooks.good())
	{	

		//Strings to store title, author and isbn form books.txt file
		string title;
		string author;
		string isbn;

		getline(finBooks,title);
		getline(finBooks,author);
		getline(finBooks,isbn);
		
		LibraryBook book(title,author,isbn);
		myBook[numberOfBooks] = book;

		
		//Increment to the next myBook entry 
		numberOfBooks++;
	}

 	while(finISBN.good())
	{

		for(int j =0; j<numberOfBooks; j++)
		{
			//Check to see if the book is checked out
			string theISBN;
			finISBN >> theISBN;
			if (myBook[numberOfBooks].getISBN() == theISBN)
				myBook[numberOfBooks].checkOut();
			else
				myBook[numberOfBooks].checkIn();

		}
	}


	for (int i = 0; i<=numberOfBooks; i++)
	{
		if(myBook[numberOfBooks].isCheckedOut() )
		{
		
			fout << myBook[i].getTitle() <<" " << myBook[i].getTitle() <<" " << myBook[i].getISBN() << endl;
		}
	}
	// Close the files at the end
	finBooks.close();
	finISBN.close();
	fout.close();

    // End program
	return 0;
}
