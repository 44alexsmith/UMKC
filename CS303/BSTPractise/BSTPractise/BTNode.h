
#include<string>
#include<iostream>
#include <sstream>  //For ostringstream

using namespace std;

//A node for a Binary Tree

template<typename Item_Type>
struct BTNode
{
	//Data Fields
	string data;
	BTNode<Item_Type>* left;
	BTNode<Item_Type>* right;

	//Constructor
	BTNode(const Item_Type& the_data, BTNode<Item_Type>* left_val = NULL, BTNode<Item_Type>* right_val = NULL) : data(the_data), left(left_val), right(right_val){}

	//Destructor(to  avoid warning message)
	virtual ~BTNode() {}
	
	// to_string
	virtual string to_string() const{
		ostringstream os;
		os << data;
		return os.str();
	}

}; //End BTNode

//Overloading the ostream insertion operator
template<typename Item_Type>
ostream& operator<<(ostream& out, const BTNode<Item_type>& node)
{
	return out << node.to_string();
}