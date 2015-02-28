
/*Name: Alexeo Smith
  Date: 04/29/2014
  Class: 201L */

#include <iostream>	  //For cin cout
#include <fstream>    //Input output stream
#include <string>	//For strings
#include <list>    //For list types
using namespace std;

//Fill list function prototype
void fillList(list<char>& lstVectorParam, string inputStringParam);

//Function to print the list
void printList(list<char>& lstParam, ostream& outputStream);

//Remove character function
void removeCharacter(list<char>& lstParam, char& charParam);

int main()
{


	ifstream fin("input.txt");   //Link the input file
	ofstream fout("output.txt");  //Link to an output file

	list<char> strList;   //A char list type
	string lineFromFile;		//Variable to hold the data from the input file

	//List of vowels to remove from the list 
	char vowels[] = {'a', 'A', 'E','e', 'I','i','O','o','U','u' }; 

	while(!fin.eof())  //run unit the end of hte file
	{
		getline(fin,lineFromFile);		//get a line of text
		if(lineFromFile == "END")
			break;
		fillList(strList,lineFromFile);  //fill strList with a line of text
		for(int i = 0; i < 10; i++)		//Check for each vowel in the list 
			removeCharacter(strList,vowels[i]);  //Remove vowel function
		printList(strList,fout);  //Write the list to a file
		strList.clear();		 //Clear the current list 
	}


	return 0;


}


void fillList(list<char>& lstParam, string inputStringParam)
{

			for(int i = 0; i< inputStringParam.size(); i++)
			{
				lstParam.push_back(inputStringParam[i]);
			}
}

void printList(list<char>& lstParam, ostream& outputStream)
{

	for( list<char>::iterator iter = lstParam.begin(); iter != lstParam.end(); iter++)
		outputStream << "[" <<*iter<<"]" <<" -> ";
	outputStream << " 0 " << "\n" << endl;		
}

void removeCharacter(list<char>& lstParam, char& charParam)
{

	for( list<char>::iterator iter = lstParam.begin(); iter != lstParam.end();)
	{

		if(*iter == charParam)
			iter = lstParam.erase(iter);
		else
			iter++;

	}
}

