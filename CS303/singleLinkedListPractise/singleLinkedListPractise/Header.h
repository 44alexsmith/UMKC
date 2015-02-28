
#include <stddef.h>

template<typename Item_Type>
struct Node
{
	Item_Type data; //Variable to hold the data
	Node* next;  //pointer to the next node

	//Constructor
	Node(const Item_Type& data_item, Node* next_ptr = NULL) : data(data_item), next(next_ptr) {}

};