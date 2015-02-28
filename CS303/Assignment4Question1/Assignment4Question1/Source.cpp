#include <iostream>

using namespace std;



int main()
{
	int mystery(int);  //Function prototype

	int answer = mystery(4);
	cout << answer;

	system("pause");
	return 0;
}


int mystery(int n) 
{
	if (n == 0)
		return 0;
	else
		return n * n + mystery(n - 1);
}