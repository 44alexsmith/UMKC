#include <string>
#include <iostream>

using namespace std;

int main()
{
	/*void print(int); //Function prototype
	void countUp(int); 

	
	//Count down
	print(4);
	cout << endl << endl;
	cout << "----------------------------------------------------------" <<endl;


	countUp(3);*/

	/*bool isPrime(int, int i= 2);

	if (isPrime(10))
		cout << "True";
	else
		cout << "False";*/

	int sum(int);

	sum(4);


	cout << endl;
	system("pause");
}

/*void print(int p)
{
	if (p == 0)
		return;
	cout << p << " ";
	print(p-1);
	return;
	
}

void countUp(int c)
{
	
	if (c == 11)
		return;
	cout << c << " ";
	print(c+1);
	
	return;

}*/

/*bool isPrime(int p, int i)
{
	if (i == p) return 1;//or better  if (i*i>p) return 1;
	if (p%i == 0) return 0;
	return isPrime(p, i + 1);

}*/

int sum(int num)
{
	if (num == 0)
		return 0;
	return (sum(num - 1) + (num));
}