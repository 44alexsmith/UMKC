// Alexeo Smith
// 4/08/2014
// Lab 9


#include <fstream>
#include <iostream>
#include <string>
#include <map>

using namespace std;


//Create a map for the Words
map<string, int> myMap;

// Starting point
int main()
{
	// File I/O
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	// Read in file
	string wordIn;
	
	// While there are more words
	while(fin >> wordIn)
	{
		//If the word doesn't exist, add it, else it finds it
		myMap[wordIn]++;
	}

	//Print the size of the map
	fout << "Words found: " << myMap.size() << endl;


	//Loop through and print the first and second column of the map
	for(map<string, int>::iterator iter = myMap.begin(); iter != myMap.end(); iter++)
	{
		fout << iter->first << " - " << iter->second << endl;
	}

}


