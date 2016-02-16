// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #2
 * Shape Class Implementation
 * Professor: Robert  Benkoczi
 * Program Name: ShapeContainer.cc
 * Software Used: Geany
*/
#include "ShapeContainer.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iostream>
/// Class Implementation
/**
 * Impelmentation which defines all methods prototyped in the class
 * interface
**/
ShapeContainer::ShapeContainer()
{
	// Ensure the list is clear
	shList.clear();
}

ShapeContainer::~ShapeContainer()
{
	shList.clear();
}

/// Insert Function
/**
 * Ensures that the number of triangles inserted are random and
 * that all other shapes are assigned in accordance to their
 * values. Please note that the final value is only applicable to
 * the triangle shape.
**/
void ShapeContainer::insert(std::string shape, double sideLength,
							double originx, double originy, double degreeRotation)
{
	// Check what shape the user is trying to draw. The final value
	// in the function is only used when building the triangle shape
	if (shape == "triangle")
	{
		shList.push_back(new Triangle(sideLength, originx, 
			             originy, degreeRotation));
	}
	else if (shape == "square")
		shList.push_back(new Square(sideLength, originx, originy));
	else if (shape == "circle")
		shList.push_back(new Circle(sideLength, originx, originy));
	else
		std::cout << "That is not a defined shape!" << std::endl;
}

void ShapeContainer::draw()
{
	// Iterator for the shape pointer list
	std::list<Shape*>::iterator it;
	Shape* currentShape;
	
	// Iterator through the list and call the draw function on each
	// one
	for(it = shList.begin(); it != shList.end(); ++it)
	{
		currentShape = *it;
		currentShape->draw(currentShape->origin.getX(),
						   currentShape->origin.getY());
	}
}

void ShapeContainer::randomTranslate()
{
	std::list<Shape*>::iterator it;
	Shape* currentShape;
	Vector randomTranslateVector;
	
	// Iterate through the container and apply a random Translate
	// vector to each
	for(it = shList.begin(); it != shList.end(); ++it)
	{
		randomTranslateVector.setX(rand() % 801 - 400);
		randomTranslateVector.setY(rand() % 601-300);
		currentShape = *it;
		currentShape->translate(randomTranslateVector);
	}
}

void ShapeContainer::deleteShapes()
{
	// Delete pointed element first before poping the pointer off
	// of the list
	while(!shList.empty())
	{
		delete shList.back();
		shList.pop_back();
	}
}
