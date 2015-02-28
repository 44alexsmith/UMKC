// Alexeo Smith
// 02/11/2014
// Lab #3


#ifndef POINT_H
#define POINT_H


// Define your class here

class Point
{
	private:
		double x, y,z;		//Private variables	


	public:					//Public functions
		Point();			//Constructor
		void setCoordinates(double, double, double);
		double calcDistance();
		double calcDistance(Point);
		
};




#endif