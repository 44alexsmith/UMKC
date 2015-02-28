// Alexeo Smith
// 03/04/2014
// Lab 6

#include "LibraryBook.h"

LibraryBook::LibraryBook()
{
	title = "";
	author = "";
	isbn = 0;
}
LibraryBook::LibraryBook(string newTitle, string newAuthor, int newIsbn)
{
	title = newTitle;
	author = newAuthor;
	isbn = newIsbn;
}

string LibraryBook::getTitle()
{
	return title;
}

string LibraryBook::getAuthor()
{
	return author;
}

int LibraryBook::getIsbn()
{
	return isbn;
}
	