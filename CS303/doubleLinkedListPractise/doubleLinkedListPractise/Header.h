#include<stddef.h>
template<typename Item_type>
struct DNode{

	//Variable for the data
	Item_type data;

	//Pointer to the previous Node
	DNode* prev;

	//Pointer to the next node
	DNode* next;


	DNode(Item_type data_item, DNode* prev_node= NULL, DNode* next_node= NULL) : data(data_item), prev(prev_node), next(next_node){}

};

