
#include<iostream>
#include<string>
#include <sstream>


using namespace std;

int main()
{
	int to_Number(string, int); //Function prototype
	string expression = "3ac4";  //Sample string

	
	int result = to_Number(expression, 0);  //Pass the string to the function
	cout << result;
	system("pause");  //Freeze the console window
	
	return 0;
}

int to_Number(string& expression, int sum=0)
{
	// Process each token
	istringstream tokens(expression);
	char next_char;
	if (tokens.eof())
		return sum;
	else
		tokens >> next_char;
		if (isdigit(next_char))
		{
			tokens.putback(next_char);
			int value;
			tokens >> value;
			sum += value;
		}
	return to_Number(expression, sum);

}