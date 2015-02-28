//Name: Alexeo Smith
//Date: 04/15/2014
//Lab: 10


#include <iostream>  //Input output
#include <fstream>	// file stream
#include <cstdlib>  //for exit 

using namespace std;



int main()
{

	//Create a variable to hold the input sgtream
	ifstream fin;
	ofstream fout;

	//Open the appropriate text file
	fin.open("inputpages.txt");
	if (!fin.good())
	{
		cout << "Check the input file." << endl;
		exit(1);  //Exit if the input file is not found
	}

	fout.open("outputpages.txt");
	if (!fout.good())
	{
		cout << "Unable to create ouput file." << endl;
		exit(1);  //Unable to create output file
	}


	int group1Page;			//Variable for the first group
	int numberOfPages = 0;  //Variable to store the number of pages
	int pageNumber = 0;		//Variable to store the page number

	//Variables to store the three other three numbers
	int otherNumber2 = 0;
	int otherNumber3 = 0;
	int otherNumber4 = 0;


	do
	{
		int pageGroup = 1;		//Variable for the various groups
		fin >> numberOfPages; //read in the number of pages
		fin >> pageNumber;
		
		if(numberOfPages > 0)  // read in the page number
		{ 
			  

			if(pageNumber % 2 == 0)  //So odd = 1, even = 2
				pageGroup++;
			else if(pageNumber>(numberOfPages/2))
				pageGroup += 2;

			switch(pageGroup)
			{
				case 1:
				{
					group1Page = pageNumber;
					break;
				}
				case 2:
				{
					group1Page = pageNumber -1;
					break;
				}
				case 3:
				{
					group1Page = numberOfPages - pageNumber;
					break;
				}

				case 4:
				{
					group1Page = (numberOfPages - pageNumber) + 1;
					break;
				}

			}//End the switch loop

			//Algorithm to callculate the other numbers 		
			otherNumber2 = group1Page + 1;
			otherNumber3 = numberOfPages - group1Page;
			otherNumber4 = (numberOfPages+1)-group1Page;

			fout << "Input: " << numberOfPages << " " << pageNumber << " " << "Output: ";
		
			if(pageNumber != group1Page)
				fout << group1Page << " ";
			if(pageNumber != otherNumber2)
				fout << otherNumber2 << " ";
			if(pageNumber != otherNumber3)
				fout << otherNumber3 << " ";
			if(pageNumber != otherNumber4)
				fout << otherNumber4 << "\n";
			
		}
	
		}while(!fin.eof());


	

	return 0;
}

