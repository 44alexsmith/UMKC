// Alexeo Smith
// 02/25/2014
// Lab 5

#include <iostream>
using namespace std;

class Fraction
{

// Add the variables and functions you need to. getGCD and reduce are 
// provided for you.
	

private:
	int getGCD( int num1, int num2 );

	//Create the necessary private variables to store the fraction components
	int numerator;
	int denominator;

public:
	void reduce();

	//Create the fraction contrucstor
	Fraction();
	
	//Create friend functions
	friend ostream& operator <<(ostream& output, const Fraction& fact);
	friend istream& operator >>(istream& input, Fraction& fact);

	//Overload the necessary operators
	const Fraction operator+(Fraction rightHandSide);
	const Fraction operator-(Fraction rightHandSide);
	const Fraction operator *(Fraction rightHandSide);
	const Fraction operator /(Fraction rightHandSide);
	bool operator == (Fraction rightFactionSide);

};

