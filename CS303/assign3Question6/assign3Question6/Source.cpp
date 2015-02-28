#include "Infix_To_Postfix.h"
#include "Syntax_Error.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{

	string expression("y - 7 * 35 + 4 / 6 - 10");

	Infix_To_Postfix myEvaluator;
	myEvaluator.convert(expression);



	return 0;
}