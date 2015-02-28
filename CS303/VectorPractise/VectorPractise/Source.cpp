#include <iostream>
#include <vector>

using namespace std;

int main()
{

	vector<string> nameList;

	cout << "Num of items in the list:" << endl;
	for (int i = 0; i < 2; i++){
		if (nameList.empty())
			cout << "The list initially has zero items";
		else
			cout << "The list has " << nameList.size() << " items." << endl;

		nameList.push_back("Ralph");
		nameList.push_back("Walter");
		nameList.push_back("Frank");
		nameList.push_back("Sam");
		nameList.push_back("Sandra");

	}

	//Here is the contents of the original list
	for (vector<string>::iterator it = nameList.begin(); it != nameList.end(); it++){
		cout << it->c_str() << endl;
	}

	//Remove one item from the end of the list
	nameList.pop_back();
	cout << "\nThe Last item(Sandra) has been removed form the list" << endl;
	cout << "\nHere is the contents of the list now" << endl;
	for (vector<string>::iterator it = nameList.begin(); it != nameList.end(); it++){
		cout << it->c_str() << endl;
	}
	cout << "-------------------------" << endl;

	//Item three has been removed from the list
	cout << "\n Print out the value at index 1" << endl;
	nameList.erase(1);
	cout << nameList.at(1) << endl;

	
	cout << "\nBelow is the new list" << endl;
	for (vector<string>::iterator iter = nameList.begin(); iter != nameList.end(); iter++){
		cout << iter->c_str() << endl;
	}
		


	system("Pause");

	return 0;
}