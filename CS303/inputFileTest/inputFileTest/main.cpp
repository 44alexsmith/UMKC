#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	
	string inputDueDate;
	string inputDescription;
	string inputAssignedDate;
	string inputStatus;


	//Link the intput file to a variable
	ifstream fin("input.txt");

	//Throw in errror if the input file is not found
	if (!fin)
	{
		cout << "Cannot open the file" << endl;
		system("pause");
	}

	//Get the input file values
	while (fin.good())
	{
		//Get the input values
		fin >> inputDueDate;
		fin >> inputDescription;
		fin >> inputAssignedDate;
		fin >> inputStatus;
	}



	system("pause");
	return 0;
}