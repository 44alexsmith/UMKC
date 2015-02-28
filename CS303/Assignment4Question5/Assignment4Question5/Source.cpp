
#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main()
{
	const int SIZE = 4; //Size of the vector
	
	vector<int> vectorIntsAscendingOrder(SIZE); //Vector in ascending order
	vector<int> vectorIntsDescendingOrder(SIZE); //Vector in desceding order
	vector<int> vectorIntsRandomOrder(SIZE);   //Vecotor with random numbers

	//Function prototypes
	void bubble_sort(vector<int>&); //Bubble sort function 
	void generateTheVectors(vector<int>&, vector<int>&, vector<int>&); //Function to generate the three vectors
	void printTheVector(vector<int>&);  //Fuction to print a vector
	

	//Pass the vectors to the arrangement function
	generateTheVectors(vectorIntsAscendingOrder, vectorIntsDescendingOrder, vectorIntsRandomOrder);
	

	//Sort the vector via the Bubble Sort function
	bubble_sort(vectorIntsDescendingOrder);
	printTheVector(vectorIntsDescendingOrder);  //Print the sorted vector
	

	system("pause");
}


//Bubble sort function
void bubble_sort(vector<int>& vec){
	int pass = 1;
	bool exchanges;
	do {
		exchanges = false;  // No exchanges yet.
		for (int first_of_pair = 0;
			first_of_pair < vec.size() - pass; ++first_of_pair) {
			int second_of_pair = first_of_pair + 1;

			if (vec[second_of_pair] < vec[first_of_pair]) {
				// Exchange pair.
				int temp = vec[first_of_pair];
				vec[first_of_pair] = vec[second_of_pair];
				vec[second_of_pair] = temp;
				exchanges = true;  // Set flag.
			}
		}
		pass++;

	} while (exchanges);

}

void generateTheVectors(vector<int>& v_asec, vector<int>& v_desc, vector<int>& v_rand)
{
	//Populate the 1st vector in ascending order
	for (int i = 0; i < v_asec.size(); i++)
	{
		v_asec[i] = i;
		cout << v_asec[i] << " ";
	}
	cout << endl;

	//Populate the 2nd vector in descending order
	for (int j = v_desc.size() - 1; j >= 0; j--)
	{
		v_desc[j] = j;
		cout << v_desc[j] << " ";
	}
	cout << endl;


	//Populate the 3rd vector with random numbers
	for (int k = 0; k < v_rand.size(); k++)
	{
		v_rand[k] = (rand() % v_rand.size() - 0 + 1);
		cout << v_rand[k] << " ";
	}
	cout << endl;

}

void printTheVector(vector<int>& theVector)
{
	//Populate the a vector values
	for (int l = 0; l < theVector.size(); l++)
	{
		cout << theVector[l] << " ";
	}
	cout << endl;
}