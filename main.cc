// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #1
 * Main Program
 * Professor: Robert  Benkoczi
 * Program Name: main.cc
 * Software Used: Geany
*/
#include "Display.h"
#include "ShapeContainer.h"
#include "MySimulator.h"
#include <string>
#include <ctime>
#include <allegro5/allegro_primitives.h>
#include <iostream>

/// Function Prototype: drawDisplay
/**
 * Purpose: Simple function to display the contents drawn
 *          by Allegro
**/
void drawDisplay(ShapeContainer&);

int main(void)
{
	// Make the rand function truly random
	srand(time(0));
	
	// Variable Declarations
	double randNumOfShapes = rand() % 16 + 5;
	int degreeRotation;
	std::string shapeList[] = {"circle", "square", "triangle"};
	int shapeListSize = 3;
	int fps = 120;
	Display disp;
	int radius, originx, originy;
	ShapeContainer shapes;
	
	/**
	 * Shape inserting algorithm. The number is random between
	 * 5 and 20 and each shape has the same chance of being inserted
	**/
	
	for (int i = 0; i < randNumOfShapes; i++)
	{
		std::string currentShape = shapeList[rand() % shapeListSize];
		
		if (currentShape == "circle" || currentShape == "square")
		{
			radius = rand() % 51 + 50;
			originx = rand() % (800 - 2 * radius + 1) + radius;
			originy = rand() % (600 - 2 * radius + 1) + radius;
			shapes.insert(currentShape, radius, originx, originy, 0);
		}
		
		else
		{
			radius = rand() % 51 + 50;
			originx = rand() % (800 - 2 * radius + 1) + radius;
			originy = rand() % (600 - 2 * radius + 1) + radius;
			degreeRotation = rand() % 60 + 61;
			shapes.insert(currentShape, radius, originx, originy, degreeRotation);
		}
	}
	
	/// Run the Simulation!
	MySimulator simTest(disp, fps, shapes);
	simTest.simulate();
	
	shapes.deleteShapes();
	return 0;
}

/// Function definition
void drawDisplay(ShapeContainer& shapes)
{
	// Create a 800x600 window
	Display disp;
	
	// Draw the shapes
	shapes.draw();
	
	// Display the shapes
	al_flip_display();
	
	// Keep the display up for 4 seconds
	al_rest(4.0);
}
