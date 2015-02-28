// Alexeo Smith
// 03/04/2014
// Lab 6
#include "LibraryBook.h"
#include "Patron.h"
#include <string>
using namespace std;

Patron::Patron()
{
	firstName = "";
	lastName = "";
	cardNumber = 0;
	numBooks = 0;
}

Patron::Patron(string newFName, string newLName, int newCardNumber)
{
	firstName = newFName;
	lastName = newLName;
	cardNumber = newCardNumber;
	numBooks = 0;
}

Patron::~Patron()
{
	//TODO: Implement this
	 for (int i=0;i<numBooks;i++)
	 {
		delete books[i];
	 }
}

void Patron::checkOut(LibraryBook* book)
{
	//TODO: Implement this
	books[numBooks]= book;
	numBooks++;
}

int Patron::getCardNumber()
{
	//TODO: Implement this
	return cardNumber;
}

LibraryBook Patron::getBook(int bookIndex)
{
	//TODO: Implement this
	return *books[bookIndex];

}

string Patron::getName()
{
	//TODO: Implement this
	return (firstName + " " + lastName);
}

int Patron::getNumBooks()
{
	//TODO: Implement this
	return numBooks;
}