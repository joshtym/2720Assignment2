// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #2
 * Shape Class Implementation
 * Professor: Robert  Benkoczi
 * Program Name: Triangle.cc
 * Software Used: Geany
*/
#include "Triangle.h"
#include <allegro5/allegro_primitives.h>
#include <algorithm>

/// Class Implementation
/**
 * Impelmentation which defines all methods prototyped in the class
 * interface
**/

Triangle::Triangle(double givenSideLength, double originX, 
				   double originY, double givenDegreeRotation)
{
	// Assign all the given values to their respective variables
	sideLength = givenSideLength;
	origin.setX(originX);
	origin.setY(originY);
	degreeRotation = givenDegreeRotation;
	speedVector = randomSpeedVector();
	startingDegree = rand() % 360;
	updateMaxAndMin();
}

/// Main Triangle Draw Function
/**
 * Algorithm takes two points as well as the origin (which is also
 * the center of the circle). Depending on what triangle number this is
 * as well as the total number of triangles, it finds the angle away
 * theta = 0 for the first point. Then it finds the next angle from 
 * theta = 0 such that the angle in between point 1 and point 2 is
 * equal to the degree rotation. It then uses rotate algorithm to
 * find the x and y values of these "Vectors" and assigns point 1 and
 * point 2 coordinates accodingly
**/
void Triangle::draw(double originx, double originy)
{		
	p1.rotate(origin, p1, sideLength, startingDegree);
	
	p2.rotate(origin, p2, sideLength, startingDegree + degreeRotation);
		
	al_draw_triangle(origin.getX(), origin.getY(), p1.getX(),
			         p1.getY(), p2.getX(), p2.getY(),
					 al_map_rgb(50,205,50), 4);
}

void Triangle::updateMaxAndMin()
{
	// Updates p1 and p2 to the correct values before finding the
	// maximum and minimum values.
	p1.rotate(origin, p1, sideLength, startingDegree);
	p2.rotate(origin, p2, sideLength, startingDegree + degreeRotation);
	
	minimum.setX(std::min(origin.getX(), std::min(p1.getX(), p2.getX())));
	minimum.setY(std::min(origin.getY(), std::min(p1.getY(), p2.getY())));
	maximum.setX(std::max(origin.getX(), std::max(p1.getX(), p2.getX())));
	maximum.setY(std::max(origin.getY(), std::max(p1.getY(), p2.getY())));
}
