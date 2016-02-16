// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #2
 * Shape Class Interface
 * Professor: Robert  Benkoczi
 * Program Name: Triangle.h
 * Software Used: Geany
*/
#ifndef __TRIANGLE_H
#define __TRIANGLE_H

#include "Shape.h"

/// Class that initializes a Triangle object and allows for
/// drawing
/**
 * Class utilizes the idea of inheritance and takes form the
 * template of the Shape class. Defines it's own seperate draw
 * function and has a counter that keeps track of the number of
 * triangles that have been initialized so far. It also has data
 * members that store the length of one of the two equal sides
 * (due to the fact that these are all isosceles triangles) as well
 * as the angle between the two equal sides.
**/
class Triangle : public Shape
{
	private:
		double sideLength;
		double degreeRotation;
		Point p1, p2;
		double startingDegree;
	public:
		/// Constructor
		/**
		 * Constructor takes in the x and y coordinates of the origin,
		 * the length of one of the two equal sides, and the angle
		 * between the two equal sides in the isosceles triangle
		**/
		Triangle(double, double, double, double);
		
		/// Defined draw function from the purely virtual one
		/// in the shape class
		/**
		 * Defined to allow for the drawing of a triangle given
		 * it's x and y coordinates of the origin, the length of one
		 * of it's two equal sides, and the angle in between them.
		**/
		void draw(double, double);
		
		/// Defines the minimum and maximum x and y values
		void updateMaxAndMin();
};
#endif
