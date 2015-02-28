// Name: Alexeo Smith
// Due: 02/9/2015
// Assingment: CS 431 HW #2 Question 6

#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;

// Starting point
int main()
{
	//Function prototype
	int generateRandomNumber();
	int xRandomNumber = 0;  //Variable for the random number
	string bathRoomStatus = " "; //String for bathroom status
	int totalWomenInRestRoom = 0;
	int totalMenInRestRoom = 0;
	int response = -1;

	//Get a random number between 1 - 75
	int ranNum = generateRandomNumber();

	if (ranNum <= 25)
	{
		bathRoomStatus = "Empty";
		totalWomenInRestRoom = 0;
		totalMenInRestRoom = 0;
	}

	else if (ranNum > 25 && ranNum <= 50)
	{
		bathRoomStatus = "A women is present";
		totalWomenInRestRoom++;
	}
	else
	{
		bathRoomStatus = "A man is present";
		totalMenInRestRoom++;
	}

	//Kick of the random number generator
	while (response != 5)
	{
		cout << "Note: This rest room can only hold two occupants of the same sex!" <<endl;
		cout << "The rest room status is: " << bathRoomStatus << endl << endl;
		cout << "Select an option from 1 to 5 to play: " << endl;
		cout << "1) Woman wants to enter" << endl;
		cout << "2) Man wants to enter" << endl;
		cout << "3) Woman leaves" << endl;
		cout << "4) Man leaves" << endl;
		cout << "5) Quit the game" << endl;

		cin >> response; //Capture the user's response
		system("cls"); //Clear the previous menu


		if (response == 1)  // A moman wants to enter the rest room
		{
			if (totalMenInRestRoom > 0)
			{
				cout << "\n A man is in the rest room. You will have to wait until he leaves!" << endl;
				bathRoomStatus = "A man is present";
				continue;
			}
			else if (totalWomenInRestRoom == 2)
			{
				cout << "Sorry the bathroom is full to capacity.  You cannot enter at this time." <<endl;
				bathRoomStatus = "Two women are present";
				continue;
			}
			else if (totalWomenInRestRoom == 0)
			{
				totalWomenInRestRoom++;
				cout << "The woman was able to enter." << endl;
				bathRoomStatus = "A woman is present";
				continue;
			}
			else if (totalWomenInRestRoom == 1)
			{
				totalWomenInRestRoom++;
				cout << "The woman was able to enter" << endl;
				bathRoomStatus = "Two women are present";
				continue;
			}
		}
		else if (response == 2)
		{
			if (totalWomenInRestRoom > 0)
			{
				cout << "\nA woman is in the rest room, you will have to wait until she leaves." << endl;
				bathRoomStatus = "A woman is present";
				continue;
			}
			else if (totalMenInRestRoom == 2)
			{
				cout << "Sorry the bathroom is full to capacity.  You cannot enter at this time.";
				bathRoomStatus = "Two men are present";
				continue;
			}
			else if (totalMenInRestRoom == 0)
			{
				totalMenInRestRoom++;
				cout << "The man was able to enter." << endl;
				bathRoomStatus = "A man is present";
				continue;
			}
			else if (totalMenInRestRoom == 1)
			{
				totalMenInRestRoom++;
				cout << "The man was able to enter." << endl;
				bathRoomStatus = "Two men are present.";
				continue;
			}
		}
		else if (response == 3)
		{
			if (totalWomenInRestRoom == 0)
			{
				cout << "No women were present!" << endl;
				continue;
			}
			else if (totalWomenInRestRoom == 2)
			{
				totalWomenInRestRoom--;
				cout << "One lady left the rest room " << endl;
				bathRoomStatus = "One woman is present.";
				continue;
			}
			else if (totalWomenInRestRoom == 1)
			{
				totalWomenInRestRoom--;
				cout << "One woman left the rest room " << endl;
				bathRoomStatus = "Empty";
				continue;
			}
		}
		else if (response == 4)
		{
			if (totalMenInRestRoom == 0)
			{
				cout << "No men were present!" << endl;
				continue;
			}
			else if (totalMenInRestRoom == 2)
			{
				totalMenInRestRoom--;
				cout << "One man left the rest room. " << endl;
				bathRoomStatus = "One man is present.";
				continue;
			}
			else if (totalMenInRestRoom == 1)
			{
				totalMenInRestRoom--;
				cout << "One man left the rest room " << endl;
				bathRoomStatus = "Empty";
				continue;
			}
		}
	}
	return 0;
}

int generateRandomNumber()  //Function to generate a random number each time the game is played
{
	srand(time(0));  //Create a seed base on time in order to get random numbers every time
					 //the function is called
	int xRandomNumber = (rand() % 75);  //Specify the range of random numbers e.g. 1 - 75

	return xRandomNumber;  //Return the random number to the calling function
}