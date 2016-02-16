#include "SimulatorTestFixture.h"
// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #2
 * Main Program
 * Professor: Robert  Benkoczi
 * Program Name: SimulatorTestFixture.cc
 * Software Used: Geany
*/
#include "Triangle.h"
#include "Square.h"
#include "Circle.h"
#include "Shape.h"
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>

/// Class Implementation
/**
 * Impelmentation which defines all methods prototyped in the class
 * interface
**/

void SimulatorTestFixture::setUp()
{
	// Assign new shapes on the heap
	testCircle = new Circle(50, 200, 100);
	testSquare = new Square(75, 600, 400);
	testTriangle = new Triangle(50, 400, 300, 60);
	
	// Get maximum width and height values
	Display d;
	displayWidth = d.getW();
	displayHeight = d.getH();
	
	// Assign a time to test in
	time = 1;
}

void SimulatorTestFixture::tearDown()
{
	// Deallocate all allocated resources
	delete testCircle;
	delete testSquare;
	delete testTriangle;
}

bool SimulatorTestFixture::isXTooLow(Shape& t)
{
	if (t.getMinX() <= 0)
		return true;
	return false;
}

bool SimulatorTestFixture::isXTooHigh(Shape& t)
{
	if (t.getMaxX() >= displayWidth)
		return true;
	return false;
}

bool SimulatorTestFixture::isYTooLow(Shape& t)
{
	if (t.getMinY() <= 0)
		return true;
	return false;
}

bool SimulatorTestFixture::isYTooHigh(Shape& t)
{
	if (t.getMaxY() >= displayHeight)
		return true;
	return false;
}

void SimulatorTestFixture::testXTooLow()
{
	updateModel(time);
	
	CPPUNIT_ASSERT(!(isXTooLow(*testTriangle)));
	CPPUNIT_ASSERT(!(isXTooLow(*testSquare)));
	CPPUNIT_ASSERT(!(isXTooLow(*testCircle)));
}

void SimulatorTestFixture::testXTooHigh()
{
	updateModel(time);
	CPPUNIT_ASSERT(!(isXTooHigh(*testTriangle)));
	CPPUNIT_ASSERT(!(isXTooHigh(*testSquare)));
	CPPUNIT_ASSERT(!(isXTooHigh(*testCircle)));
}

void SimulatorTestFixture::testYTooLow()
{
	updateModel(time);
	CPPUNIT_ASSERT(!(isYTooLow(*testTriangle)));
	CPPUNIT_ASSERT(!(isYTooLow(*testSquare)));
	CPPUNIT_ASSERT(!(isYTooLow(*testCircle)));
}

void SimulatorTestFixture::testYTooHigh()
{
	updateModel(time);
	CPPUNIT_ASSERT(!(isYTooHigh(*testTriangle)));
	CPPUNIT_ASSERT(!(isYTooHigh(*testSquare)));
	CPPUNIT_ASSERT(!(isYTooHigh(*testCircle)));
}

void SimulatorTestFixture::testForCorner()
{
	updateModel(time);
	CPPUNIT_ASSERT(!(isXTooLow(*testTriangle) && isYTooLow(*testTriangle)));
	CPPUNIT_ASSERT(!(isXTooLow(*testTriangle) && isYTooHigh(*testTriangle)));
	CPPUNIT_ASSERT(!(isXTooHigh(*testTriangle) && isYTooLow(*testTriangle)));
	CPPUNIT_ASSERT(!(isXTooHigh(*testTriangle) && isYTooHigh(*testTriangle)));
	
	CPPUNIT_ASSERT(!(isXTooLow(*testCircle) && isYTooLow(*testCircle)));
	CPPUNIT_ASSERT(!(isXTooLow(*testCircle) && isYTooHigh(*testCircle)));
	CPPUNIT_ASSERT(!(isXTooHigh(*testCircle) && isYTooLow(*testCircle)));
	CPPUNIT_ASSERT(!(isXTooHigh(*testCircle) && isYTooHigh(*testCircle)));
	
	CPPUNIT_ASSERT(!(isXTooLow(*testSquare) && isYTooLow(*testSquare)));
	CPPUNIT_ASSERT(!(isXTooLow(*testSquare) && isYTooHigh(*testSquare)));
	CPPUNIT_ASSERT(!(isXTooHigh(*testSquare) && isYTooLow(*testSquare)));
	CPPUNIT_ASSERT(!(isXTooHigh(*testSquare) && isYTooHigh(*testSquare)));
}

void SimulatorTestFixture::updateModel(double dt)
{
	testTriangle->origin.setX(testTriangle->origin.getX() + dt*testTriangle->speedVector.getX());
	testTriangle->origin.setY(testTriangle->origin.getY() + dt*testTriangle->speedVector.getY());
	testTriangle->updateMaxAndMin();
	
	testSquare->origin.setX(testSquare->origin.getX() + dt*testSquare->speedVector.getX());
	testSquare->origin.setY(testSquare->origin.getY() + dt*testSquare->speedVector.getY());
	testSquare->updateMaxAndMin();
	
	testCircle->origin.setX(testCircle->origin.getX() + dt*testCircle->speedVector.getX());
	testCircle->origin.setY(testCircle->origin.getY() + dt*testCircle->speedVector.getY());
	testCircle->updateMaxAndMin();
}
