// Alexeo Smith
// 02/18/2014
// Lab #4

#include "LibraryBook.h"
#include <string>
using namespace std;

LibraryBook::LibraryBook()			//default constructor the the library book
{	
	//Initialize the variables
	 title = "";
	 author = "";
	 isbn = "";
	checkedOut = false;

}

LibraryBook::LibraryBook(string titleParam, string authorParam, string isbnParam)  //Overloaded constructor
{

	//Initialize the variables
	title = titleParam;
	author = authorParam;
	isbn = isbnParam;
	
}

//Get the book title
string LibraryBook::getTitle()
{	
	return title;
}
	
string LibraryBook::getAuthor()		//get the Authoer
{	

	return author;
}


string LibraryBook::getISBN()		//Get the ISBN number
{	
	return isbn;
}

void LibraryBook::checkOut()	//Change the status to checked out
{	
	checkedOut = true;

}
void LibraryBook::checkIn()		//Changed the status to checked in
{	
	checkedOut = false;
}

bool LibraryBook::isCheckedOut()  //Return status of the book
{
	return checkedOut;
}