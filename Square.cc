// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #2
 * Shape Class Implementation
 * Professor: Robert  Benkoczi
 * Program Name: Square.cc
 * Software Used: Geany
*/
#include "Square.h"
#include <allegro5/allegro_primitives.h>

/// Class Implementation
/**
 * Impelmentation which defines all methods prototyped in the class
 * interface
**/

Square::Square(double halfSideLength, double originx,
			   double originy)
{
	// Assign given values to the appropiate sections
	origin.setX(originx);
	origin.setY(originy);
	sideLength = 2*halfSideLength;
	speedVector = randomSpeedVector();
	
	// Based on the given values, calculates the maximum and minimum
	// x and y coordinates
	updateMaxAndMin();
}

void Square::draw(double originx, double originy)
{
	// Use allegro's draw function to draw the shape into the buffer
	al_draw_rectangle(originx - sideLength/2, originy - sideLength/2,
	                  originx + sideLength/2, originy + sideLength/2, 
	                  al_map_rgb(255,255,0), 4);
}

void Square::updateMaxAndMin()
{
	minimum.setX(origin.getX() - sideLength/2);
	minimum.setY(origin.getY() - sideLength/2);
	maximum.setX(origin.getX() + sideLength/2);
	maximum.setY(origin.getY() + sideLength/2);
}
	
