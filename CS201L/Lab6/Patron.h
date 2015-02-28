// Alexeo Smith
// 03/04/2014
// Lab 6

#include "LibraryBook.h"
#include <string>
using namespace std;

// Ensure this file isn't included more than once
#ifndef PATRON_H
#define PATRON_H

class Patron
{
public:
	Patron();
	Patron(string newFName, string newLName, int newCardNumber);
	~Patron();

	void checkOut(LibraryBook* book);

	int getCardNumber();
	LibraryBook getBook(int bookIndex);
	string getName();
	int getNumBooks();

private:
	string firstName;
	string lastName;
	LibraryBook* books[10];
	int cardNumber;
	int numBooks;
};

#endif