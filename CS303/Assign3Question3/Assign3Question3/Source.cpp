#include <iostream>  //For basic input/output
#include <fstream>   //File stream library
#include <list>      //List library
#include <string>    //For strings

using namespace std;

int main()
{
	list<string> listOfWords;  //Create a list container of strings
	string word;	//Create a variable to store each word from the input file

	ifstream fin("input.txt"); //Create a link to the input file
	if (fin.fail()) //Throw an error if the input file cannot be open and exit the program
	{
		cout << "Unable to open the input file" << endl;
		system("pause");
		return 0;
	}

	while (!fin.eof()) //While the end of the input file has not be reached
	{
		fin >> word;  //Store each word in a variable called word
		listOfWords.push_back(word); //Add each word to the list
	}
	listOfWords.reverse(); //Reverse the order of the words in the list
	
	//Iterate through the list and print out each word
	for (list<string>::iterator iter = listOfWords.begin(); iter != listOfWords.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl; //Do a carriage return
	system("pause"); //Pause the output on the screen for the end user

	return 0; //Exit the program
}

