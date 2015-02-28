// Alexeo Smith
// 2/18/2014
// Lab #4

// Ensure class isn't added more than once
#ifndef LIBRARYBOOK_H
#define LIBRARYBOOK_H
#include <string>
using namespace std;

#include <string>
using namespace std;

// Write LibraryBook class here

class LibraryBook
{
	//Declare data members
	private:
		string title;
		string author;
		string isbn;
		bool checkedOut;


	public:
		LibraryBook();			//default constructor the the library book
		LibraryBook(string, string, string);  //Overloaded constructor

		string getTitle();		//Get the book title
		string getAuthor();		//get the Authoer
		string getISBN();		//Get the ISBN number
		void checkOut();	//Change the status to checked out
		void checkIn();		//Changed the status to checked in
		bool isCheckedOut();  //Return status of the book


};

// This matches #ifndef at beginning of the file, so leave it in
#endif