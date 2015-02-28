
// Alexeo Smith
// 03/18/2014
// Lab 7


#pragma once
#include <string>

using namespace std;

class Word
{

private:
	string word;
	int counter;


public:
	Word(void);
	Word(string, int);
	//Word(string);		//This constructor will build the word object to store that word
						// internally, and set its initial count

	void increment();	//Increment the counter
	string getWord();	//to return word
	int getCounts();	//return the count

	void setWord(string);	//Sets the value
	void setCount(int);		//Sets the count
			
};



