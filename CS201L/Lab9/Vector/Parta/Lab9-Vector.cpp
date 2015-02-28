// Alexeo Smith
// 04/08/2014
// Lab 9

#include "Word.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


// Starting point
int main()
{
	// File I/O
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	//Create a vector Word object
	vector<Word> essay;

	// Read in file
	string wordIn;
	// While there are more words
	while(fin >> wordIn)
	{
		// It's not found by default
		bool found = false;
		
		// For each element in the vector array, if it exists, increment its count, and mark it as found
		for(vector<Word>::iterator iter = essay.begin(); iter != essay.end(); iter++)
		{
			if(iter->getWord() == wordIn)
			{	
				iter->increment();
				found = true;
				// Quit for loop early
				break;
			}
			
		}
		if(!found) // If not found, add it. 
		{	
			Word obj;
			obj.setWord(wordIn);
			obj.setCount(1);
			essay.push_back(obj);
					
		}
	}

	// Print list the words found
	fout << "Words found: " << essay.size() << endl;
	
	// For each word, print it's word/count pair.
	for(vector<Word>::iterator iter = essay.begin(); iter != essay.end(); iter++)
	{
		fout << iter->getWord() << " - " << iter->getCount() << endl;
	}

}



