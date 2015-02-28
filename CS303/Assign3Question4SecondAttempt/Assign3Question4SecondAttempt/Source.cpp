#include "Postfix_Evaluator.h"
#include "Syntax_Error.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//string expression("10 2 * 5 / 6 2 5 * + -");  //Problem 4
	string expression("10 * 5 / 6 2 5 * + -");  //Problem 5
	
	Postfix_Evaluator myEvaluator;
	myEvaluator.eval(expression);
	


	return 0;
}