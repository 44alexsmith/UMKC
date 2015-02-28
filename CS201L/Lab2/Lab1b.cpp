// Alexeo Smith
// January 28th, 2014
// Lab 1

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	char answer;
	int maxNum;

	cout << "********************************************************" << endl;
	cout << "* Welcome to the Lab 1 Multiplication Table Generator! *" << endl;
	cout << "********************************************************" << endl << endl;
	do {
		cout << "What number shall this table go up to? ";
		cin >> maxNum;

		cout << endl << "   | ";
		for (int i = 1; i <= maxNum; i++) {
			cout << setw(4) << i << " ";
		}
		cout << endl << "---+-";
		for (int i = 1; i <= maxNum; i++) {
			cout << "-----";
		}
		cout << endl;



		for (int i = 1; i <= maxNum; i++) {
			cout << setw(2) << i << " | ";
			for (int j = 1; j <= maxNum; j++) {
				cout << setw(4) << i * j << " ";
			}
			cout << endl;
		}

		cout << endl << "Would you like another table? (Y/N) ";
		answer = getchar();		// Ignore enter key
		answer = getchar();		// Get keypress

	} while (answer == 'Y' || answer == 'y');
	system("pause");
}