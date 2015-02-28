
// Alexeo Smith
// 03/18/2014
// Lab 7


#include <iostream>						
#include <fstream>						//File stream library
#include <string>
#include "Word.h"						//include the header for the word class
#include <iostream>

using namespace std;					//Standard C++ library files

int resizeArray(Word* & ,int);			//Function to resize the array dynamically


int main()
{
 int SIZE = 10;					//Initial capacity of the array
 int totalCounter = 0;

	ifstream fin("input.txt");			//Variable linked to the input.txt file
	ofstream fout("output.txt");		// Variable use to write to the output.txt file

	string wordFromFile;		//Variable to hold the words read in

	Word* myArray = new Word[SIZE]; //dynamic array, size 
	int i = 0;  //used to increment the while lop

	
	while(!(fin.eof()))
	{	
		
		fin >> wordFromFile;
		for(int j = 0; j<totalCounter; j++)
		{
			if (myArray[j].getWord() == wordFromFile)
				//myArray[i].setWord(wordFromFile);
				myArray[i].increment();

			
		}
		if(SIZE == totalCounter)
			
			SIZE = resizeArray(myArray, SIZE);
		

		
	}	
		//Print all the words an their appropriate count
		fout << "Words found: " << totalCounter << "\n";
		fout << "Array's max size:" << SIZE << "\n";
		
		for(int k = 0; k<totalCounter; k++)
			fout << myArray[k].getWord() << " - " << myArray[k].getCounts();
		return 0;

}


int resizeArray(Word* &oldArray ,int sizeParam)
{
	
	Word* newArray = new Word[sizeParam *2];
	for (int i = 0; i<sizeParam; i++)
		newArray[i].setWord(oldArray[i].getWord());

	delete [] oldArray;
	oldArray = newArray;
	sizeParam *= 2;

	return sizeParam;

}



