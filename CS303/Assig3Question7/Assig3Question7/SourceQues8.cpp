#include <iostream>
#include <string>
#include <queue>
using namespace std;


int main()
{

	void move_to_rear(queue<string>&); //Function prototype
	void initializeQueue(queue<string>&);//Function prototype

	queue<string> myqueue;  //Create a queue of strings
	string old_Value; //String to hold the queue values
	string new_Value;

	//Function to add values to the queue
	initializeQueue(myqueue);

	//Print the initial queue arrangement
	while (!myqueue.empty())
	{
		old_Value = myqueue.front();
		cout << old_Value << " ";
		myqueue.pop();
	}
	cout << endl;

	//Add values to the queue
	initializeQueue(myqueue);

	move_to_rear(myqueue); //Move the first queue entry to the rear of the queue


	//Print the new queue arrangement
	while (!myqueue.empty())
	{
		new_Value = myqueue.front();
		cout << new_Value << " ";
		myqueue.pop();
	}

	system("pause");
	return 0;
}

void move_to_rear(queue<string>& passedInQueue)
{
	string intialFrontValue = passedInQueue.front();  //Get the intial front value
	passedInQueue.push(intialFrontValue); //Push the intial value to the rear of the queue
	passedInQueue.pop(); //Pop the old front value from the queue
}

void initializeQueue(queue<string>& passedInQueue)
{
	//Add values to the queue
	passedInQueue.push("A");
	passedInQueue.push("B");
	passedInQueue.push("C");
}