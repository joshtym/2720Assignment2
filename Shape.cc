// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #2
 * Shape Class Implmenetation
 * Professor: Robert  Benkoczi
 * Program Name: Shape.cc
 * Software Used: Geany
*/
#include "Shape.h"
#include <cmath>
#include <cstdlib>

/// Class Implementation
/**
 * Impelmentation which defines all methods prototyped in the class
 * interface
**/
double Point::getX() const
{
	return x;
}

double Point::getY() const
{
	return y;
}

void Point::setX(double userX)
{
	x = userX;
}

void Point::setY(double userY)
{
	y = userY;
}

void Point::rotate(const Point& p1, Point& p2, double length, 
                   double degree)
{
	// Math to allow for the rotation around one point
	const double PI = 3.14159265358979323846;
	p2.setX(p1.getX() + length*cos(PI*degree/180));
	p2.setY(p1.getY() + length*sin(PI*degree/180));
}

double Vector::getX() const
{
	return x;
}

double Vector::getY() const
{
	return y;
}

void Vector::setX(double userX)
{
	x = userX;
}

void Vector::setY(double userY)
{
	y = userY;
}

void Shape::translate(Vector& v)
{
	// Translate function used by all children
	origin.setX(origin.getX() + v.getX());
	origin.setY(origin.getY() + v.getY());
}

double Shape::getMinX()
{
	return minimum.getX();
}

double Shape::getMinY()
{
	return minimum.getY();
}

double Shape::getMaxX()
{
	return maximum.getX();
}

double Shape::getMaxY()
{
	return maximum.getY();
}

Vector Shape::randomSpeedVector()
{
	Vector v;
	v.setX(0);
	v.setY(0);
	
	// Ensures that we don't get a zero vector
	while (v.getX() == 0 || v.getY() == 0)
	{
		v.setX(rand() % 200 - 100);
		v.setY(rand() % 200 - 100);
	}
	
	return v;
}
