// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #1
 * Shape Class Implementation
 * Professor: Robert  Benkoczi
 * Program Name: Circle.cc
 * Software Used: Geany
*/
#include "Circle.h"
#include <allegro5/allegro_primitives.h>

/// Class Implementation
/**
 * Impelmentation which defines all methods prototyped in the class
 * interface
**/

Circle::Circle(double givenRadius, double originX, double originY)
{
	// Assign all the given values to their appropiate values
	radius = givenRadius;
	origin.setX(originX);
	origin.setY(originY);
	speedVector = randomSpeedVector();
	updateMaxAndMin();
}

void Circle::draw(double originx, double originy)
{
	// Uses the allegro_primitives addon to draw a circle
	al_draw_circle(originx, originy, radius, al_map_rgb(49,94,199), 4);
}

void Circle::updateMaxAndMin()
{
	minimum.setX(origin.getX() - radius);
	minimum.setY(origin.getY() - radius);
	maximum.setX(origin.getX() + radius);
	maximum.setY(origin.getY() + radius);
}
