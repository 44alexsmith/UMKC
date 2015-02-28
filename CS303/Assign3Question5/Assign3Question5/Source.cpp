//#include "Postfix_Evaluator.h"
//#include "Infix_To_Postfix_Parens.h"

#include "Infix_To_Postfix.h"
#include "Syntax_Error.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//Problem 4
	//string expression("10 2 * 5 / 6 2 5 * + -");  
	//Postfix_Evaluator myEvaluator;
	//myEvaluator.eval(expression)
	

	//Problem 5a
	//Infix_To_Postfix myEvaluator;
	//string expression = "y - 7 * 35 + 4 / 6 - 10"; 
	//myEvaluator.convert(expression);

	//problem 5b

	Infix_To_Postfix myEvaluator;
	string expression = "(x + 15) * (3 * (4 -(5 + 7 / 2)))";  
	myEvaluator.convert(expression);

	


	return 0;
}