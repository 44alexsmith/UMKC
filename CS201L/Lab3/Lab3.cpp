// Alexeo Smith
// 02/11/2014
// Lab #3

#include <cmath>
#include <iostream>
class Point
#include "Point.h"

using namespace std;

/*// Forward declaration for calcDistance function
double calcDistance(double x1, double y1, double z1, double x2, double y2, double z2);*/


int main()
{
    // File input/output variables
	ifstream fin("input.txt");
	ofstream fout("output.txt");

    // If we can't find the input file, quit with error message.
	if(!fin)
	{
		cout << "Input file not opened!" << endl;
		exit(1);
	}


	//Declare array to store the numbers from the Input file
	Point myPoint1[20];
	Point myPoint2[20];
	
	// Declare a integer to increment though the arrays
	int i = 0; 

	//Declare values to accept the user input
	double x1;
	double y1;
	double z1;
	double x2;
	double y2;
	double z2;
	
	do										
	{
		//Get the first six values from the file
		fin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

		//Assign values to x,y,z
		myPoint1[i].setCoordinates(x1,y1,z1);
		myPoint2[i].setCoordinates(x2,y2,z2);
		 		
		//Calculate the Distance on the myPoint1 and myPoint2
		double dist = myPoint1[i].calcDistance(myPoint2[i]);
		fout << dist << endl;  //Write to the Output file the distance for the first six numbers
		i = i + 1;				//Move to the next line of six numbers

	} while(fin.good());		//Run as long as the Input file still has values
	
		cout << "You can check the output file now!" << endl;  //Let the user know the process is complete 
		system("pause");		//Give the user a chance to hit enter
		
	
		
		return 0;

		/*cout << "Input file not opened!" << endl;
		exit(1);*/


    // Close our files to ensure we save our data
	fin.close();
	fout.close();

    // End program
	return 0;
}


/*double calcDistance(double x1, double y1, double z1, double x2, double y2, double z2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}*/