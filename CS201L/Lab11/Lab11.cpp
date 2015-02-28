// Alexeo Smith
// 04/22/2014
// Lab 11

#include <algorithm>	// for cleanString function (remove_if)
#include <cctype>		// for cleanString function (ispunct, isspace, toupper)
#include <fstream>		// For input/output streams
#include <string>		// For getliner
#include <iostream>

using namespace std;

void cleanString(string& str);
bool palinDrome(string);

int main()
{
	//Open the input file
	ifstream fin;
	fin.open("input.txt");

	//Open an output file 
	ofstream fout;
	fout.open("output.txt");


	//String to store the data from the input file
	string oneLine;
	
	//String to hold the cleaned string
	string cleanedString;

	//While not the end of file
	while(!(fin.eof()))
	{	
		string tempStr;  //Store the captured string

		getline(fin, oneLine);  //read in one line at a time
		tempStr = oneLine;
		cleanString(oneLine);		//Pass the string to the clean function
		
		if(palinDrome(oneLine))
			fout << "\'" << tempStr <<"\' is a palindrome. " << "\n";
		else
			fout << "\'" << tempStr <<"\' is not a palindrome. " << "\n";
	}

}

	bool palinDrome(string stringParam)
	{

		int strLength; //get the length of the string
		strLength = stringParam.length();

		if(stringParam.empty())
			return true;
		if(stringParam[0] != stringParam[strLength-1])
			return false;
		else
			return palinDrome(stringParam.substr(1,strLength-2));
			
	}




	// Cleans the string by removing all spaces and punctuation
	// and converting it to upper case
	void cleanString(string& str)
	{
		// Erase all punctuation characters
		str.erase(remove_if(str.begin(), str.end(), ispunct), str.end());
		// Erase all whitespace characters
		str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
		// Convert all characters to uppercase
		transform(str.begin(), str.end(), str.begin(), toupper);
	}

