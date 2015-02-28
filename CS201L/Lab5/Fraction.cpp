// Alexeo Smith
// 02/25/2014
// Lab 5

#include "Fraction.h"
#include <iostream>
#include <string>
using namespace std;

// Find the greatest common denominator (GCD)
// For reducing
int Fraction::getGCD( int num1, int num2 )
{
	int remainder = num2 % num1;
	if ( remainder != 0 )
		return getGCD( remainder, num1 );
	return num1;
} 

// Reduce/simplify a fraction
void Fraction::reduce()
{
    // Alter this function later to adjust for negative values
	int gcd = getGCD(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
} 

Fraction::Fraction( )
{
	numerator = 0;
	denominator = 0;

}

//Input stream function
istream& operator >>(istream& input, Fraction& fact)
{

	input >> fact.numerator;
	string temp;
	input >> temp;
	input >> fact.denominator;

	return input;
}


//Output stream function
ostream& operator <<(ostream& output, const Fraction& fact)
{
	output << fact.numerator;
	output << "/";
	output << fact.denominator;

	return output;
}


	//Declare the fuction prototypes
	const Fraction Fraction::operator +(Fraction rightHandSide)
	{
		Fraction F; //Declare a function to return
		
		//Cross multiply
		F.numerator = (denominator* rightHandSide.numerator)+(rightHandSide.denominator *numerator);
		F.denominator = (denominator * rightHandSide.denominator);  //get a common denominator
		F.reduce();
		
		return F;

	}

	//Overload the - operator
	const Fraction Fraction::operator -(Fraction rightHandSide)
	{
		Fraction F; //Declare a function to return
		
		//Cross multiply
		F.numerator = (rightHandSide.denominator *numerator)-(denominator* rightHandSide.numerator);
		F.denominator = (denominator * rightHandSide.denominator);  //get a common denominator
		F.reduce();
		
		return F;


	}

	//Overload the * operator
	const Fraction Fraction::operator *(Fraction rightHandSide)
	{
		Fraction F;  //Declare a function to return
		F.numerator = numerator * rightHandSide.numerator;
		F.denominator = denominator * rightHandSide.denominator;
		F.reduce();
		
		return F;

	}

	//Overload the / operator
	const Fraction Fraction::operator /(Fraction rightHandSide)
	{

		Fraction F;  //Declare a function to return
		F.numerator = numerator / rightHandSide.numerator;
		F.denominator = denominator / rightHandSide.denominator;
		F.reduce();
		
		return F;

	}

	//Overload the == operator
	bool Fraction::operator ==(Fraction rightHandSide)
	{
		
		reduce();
		rightHandSide.reduce();
		return ((numerator == rightHandSide.numerator && denominator == rightHandSide.denominator));

	}