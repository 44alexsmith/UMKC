#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main()
{
	int to_Number(istringstream&, int&); //Function prototype
	
	string expression = "3l4r3q1o4"; //Sample string
	int sum = 0; //Variable to hold the sum
	
	istringstream tokens(expression);  //Input stream object

	
	int result = to_Number(tokens,sum); //Variable to store the return value of the recursive function

	cout << result << " "; //Print the returned value to the console for the end user

	system("pause");  //Freeze the console window
	return 0;
}

int to_Number(istringstream& iss, int& tally)
{

	if (iss.eof())
		return tally;
	else
	{
		char next_char;
		iss >> next_char;
		if (isdigit(next_char))
		{
			iss.putback(next_char);
			int value = 0;
			iss >> value;
			tally += value;
		}
	}
	return to_Number(iss, tally);
}





