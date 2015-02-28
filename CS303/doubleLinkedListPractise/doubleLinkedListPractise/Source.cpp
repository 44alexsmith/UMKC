#include <iostream>
#include <string>
#include "Header.h"

using namespace std;
int main()
{

	//Create the Double Linked List Nodes
	DNode<string>* tom_node = new DNode<string>("Tom");
	DNode<string>* john_node = new DNode<string>("John");
	DNode<string>* harry_node = new DNode<string>("Harry");
	DNode<string>* sam_node = new DNode<string>("Sam");

	//Linked the Nodes
	tom_node->next = john_node;
	tom_node->prev = NULL;

	john_node->next = harry_node;
	john_node->prev = tom_node;

	harry_node->next = sam_node;
	harry_node->prev = john_node;

	sam_node->next = NULL;
	sam_node->prev = harry_node;

	//Print out the initial list
	DNode<string>* current_node = tom_node;
	while (current_node != NULL)
	{
		cout << current_node->data;
		if (current_node->next != NULL)
		{
			cout << "==>";
			
		}
		current_node = current_node->next;
	}
	cout << endl;


	
	//Remove Harry from the list
	
	//Reset current node to the head of the list
	current_node = tom_node;
	
	while (current_node->next->data != "Harry")
	{
		
		current_node = current_node->next;
	}

	DNode<string>* ptr_delete = harry_node;

	current_node->next->next->prev = current_node;
	current_node->next = current_node->next->next;

	delete ptr_delete;

	
	//Print out the the modified list
	cout << "\nHarry has been removed from the list" << endl;
	current_node = john_node;
	while (current_node != NULL)
	{
		cout << current_node->data;
		
		if (current_node->next != NULL)
		{
			cout << "==>";

		}
		current_node = current_node->next;
	}
	cout << endl ;

	//Insert Sharon into the list




	system("pause");
	return 0;
}