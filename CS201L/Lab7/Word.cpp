// Alexeo Smith
// 03/18/2014
// Lab 7


#include "Word.h"


Word::Word(void)
{
	word = " ";
	counter = 0;
}


Word::Word(string w, int c)			//This constructor will build the word object to store that word
{									// internally, and set its initial count
	word = w;
	counter = c;
}


void Word::increment()	//Increment the counter
{
	counter++;
}

string Word::getWord()	//to return word
{
	return word;
}

int Word::getCounts()		//return the count
{
	return counter;
}

void Word::setWord(string w)		//Sets the word
{
	word = w;
}

void Word::setCount(int c)		//Sets the count
{
	counter = c;
}

