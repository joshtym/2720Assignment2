// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #2
 * Main Program
 * Professor: Robert  Benkoczi
 * Program Name: MySimulator.cc
 * Software Used: Geany
*/
#include "MySimulator.h"
#include "Triangle.h"
#include "Circle.h"
#include "Square.h"

/// Class Implementation
/**
 * Impelmentation which defines all methods prototyped in the class
 * interface
**/

MySimulator::MySimulator(const Display& disp, int frames, 
						 ShapeContainer& givenShapes) : 
						 Simulator(disp, frames), shapes(givenShapes)
{
	// Determine the width and height of the shape
	displayWidth = disp.getW();
	displayHeight = disp.getH();
}

void MySimulator::updateModel(double dt)
{
	Shape* shape;
	std::list<Shape*>::iterator it;
	
	// Iterate through the container and update each shape
	for (it = shapes.shList.begin(); it != shapes.shList.end(); ++it)
	{
		shape = *it;
		shape->origin.setX(shape->origin.getX() + dt*shape->speedVector.getX());
		shape->origin.setY(shape->origin.getY() + dt*shape->speedVector.getY());
		shape->updateMaxAndMin();
		
		// Ensure that shape stays in bounds
		checkLessThanXAxis(shape);
		checkGreaterThanXAxis(shape);
		checkLessThanYAxis(shape);
		checkGreaterThanYAxis(shape);
	}
}

void MySimulator::drawModel()
{
	// Clear and then redraw
	al_clear_to_color(al_map_rgb(0,0,0));
	shapes.draw();
	al_flip_display();
}

void MySimulator::simulate()
{
	run();
}

void MySimulator::checkLessThanXAxis(Shape* shape)
{
	if (shape->getMinX() <= 0)
	{
		shape->origin.setX(shape->origin.getX() + (0 - shape->getMinX()));
								 
		shape->speedVector.setX((shape->speedVector.getX())*-1);
	}
}

void MySimulator::checkGreaterThanXAxis(Shape* shape)
{
	if (shape->getMaxX() >= displayWidth)
	{
		shape->origin.setX(shape->origin.getX() - (shape->getMaxX() - displayWidth));
								 
		shape->speedVector.setX((shape->speedVector.getX())*-1);
	}
}

void MySimulator::checkLessThanYAxis(Shape* shape)
{
	if (shape->getMinY() <= 0)
	{
		shape->origin.setY(shape->origin.getY() + (0 - shape->getMinY()));
								
		shape->speedVector.setY((shape->speedVector.getY())*-1);
	}
}

void MySimulator::checkGreaterThanYAxis(Shape* shape)
{
	if (shape->getMaxY() >= displayHeight)
	{
		shape->origin.setY(shape->origin.getY() - (shape->getMaxY() - displayHeight));
				
		shape->speedVector.setY((shape->speedVector.getY())*-1);
	}
}
