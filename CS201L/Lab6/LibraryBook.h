// Your name
// Today's date
// Lab 6

#include <string>
using namespace std;

// Ensure this file isn't included more than once
#ifndef LIBRARYBOOK_H
#define LIBRARYBOOK_H

class LibraryBook
{
public:
	LibraryBook();
	LibraryBook(string newTitle, string newAuthor, int newIsbn);

	string getTitle();
	string getAuthor();
	int getIsbn();
	
private:
	string title;
	string author;
	int isbn;

};

#endif