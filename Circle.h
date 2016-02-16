// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #1
 * Circle Class Interface
 * Professor: Robert  Benkoczi
 * Program Name: Circle.h
 * Software Used: Geany
*/
#ifndef __CIRCLE_H
#define __CIRCLE_H

#include "Shape.h"

/// Class that initializes a Circle object and allows for 
/// drawing
/**
 * Class utilizes the idea of inheritance and takes form the
 * template of the Shape class. Defines it's own seperate draw
 * function and has one data member, the radius
**/
class Circle : public Shape
{
	private:
		// Main data member
		double radius;

	public:
		/// Constructor
		/**
		 * Constructor takes in the x and y coordinates of the origin
		 * as well as the radius of the circle and assigns them
		 * all to the appropiate values
		**/
		Circle(double, double, double);
		
		/// Defined draw function from the purely virtual one
		/// in the shape class
		/**
		 * Defined to allow for the drawing of a circle given
		 * it's x and y coordinates of the origin as well as the
		 * radius
		**/
		void draw(double, double);
		void updateMaxAndMin();
};
#endif
