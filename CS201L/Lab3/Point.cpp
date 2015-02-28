// Alexeo Smith
// Today's date
// Lab #3

#include "Point.h"
#include <iostream>

// Define your class's functions here
Point::Point()		//Constructor
{
	//initialize the variables to zero
	x = 0;
	y = 0;
	z = 0;

}

void Point::setCoordinates(double a, double b, double c )
{
	//Set the values for x, y and z
	x = a;
	y = b;
	z = c;
}


double Point::calcDistance()
{

	//Use the Distance formula to calculate the distance of x,y,z from zero
	double result = ((x-0)*(x-0))+((y-0)*(y-0))+((z-0)*(z-0));
	double distance = sqrt(result);  //Take the square root of the previous line

	return distance;			//Return the result to the main() function


}

double Point::calcDistance(Point myPoint)
{

	//Use the Distance formula to calculate the distance of x,y,z set of values
	double result = ((x-myPoint.x)*(x-myPoint.x))+((y-myPoint.y)*(y-myPoint.y))+((z-myPoint.z)*(z-myPoint.z));
	double distance = sqrt(result);  //Take the square root of the previous line

	return distance;				//Return the result to the main() function
}