
#include "Header.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{

	/*Node<string>* head = new Node<string>("Sam", NULL);
	head = new Node<string>("Harry", head);
	head = new Node<string>("John", head);
	head = new Node <string>("Tom", head);*/

	//Node<string>* current_node = head;  //Pointer to the start of the List
	/*while (current_node != NULL)
	current_node = current_node->next;
	if (current_node->data == "Sam")
	bob->next = current_node;*/

	//Create the Linked List manually
	Node<string>* tom_node = new Node<string>("Tom");
	Node<string>* john_node = new Node<string>("John");
	Node<string>* harry_node = new Node<string>("Harry");
	Node<string>* sam_node = new Node<string>("Sam");

	//Point each node to the succeeding node
	tom_node->next = john_node;
	john_node->next = harry_node;
	harry_node->next = sam_node;

	//Create a bob node
	Node<string>* bob_node = new Node<string>("Bob", NULL); 
	
	//Place Bob between Harry and Sam
	bob_node->next = harry_node->next;
	harry_node->next = bob_node;


	Node<string>* current_node = tom_node;
	while ((current_node != NULL))
	{
		//Print out the data value for each node
		cout << current_node->data;

		//Print out an arrow between each node
		if ((current_node->next != NULL))
		{
			cout << "-->";

		}
		//Advance to the next node
		current_node = current_node->next;
	}
	cout << endl; //print a new line
	//Pause the output on the console
	
	
	//Delete Bob
	Node<string>* ptr = bob_node;
	harry_node->next = sam_node;
	delete ptr;

	//Print out the new list
	cout << "\n List after Bob as been deleted" << endl <<endl;
	
	//Reset Tom to the head node
	current_node = tom_node;
	while (current_node != NULL)
	{
		cout << current_node->data;

		if (current_node->next != NULL)
			cout << "-->";

		current_node = current_node->next;
	}
	cout << endl;  //Print out a new line
	system("pause");
		


	return 0;
}
