// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #2
 * Main Program
 * Professor: Robert  Benkoczi
 * Program Name: SimulatorTestFixture.h
 * Software Used: Geany
*/
#ifndef __SIMULATOR_TEST_FIXTURE_H
#define __SIMULATOR_TEST_FIXTURE_H

#include "MySimulator.h"
#include "Triangle.h"
#include "Square.h"
#include "Circle.h"
#include "Shape.h"
#include <cppunit/extensions/HelperMacros.h>

/// Class that inherits the functions from the CPPUnit::TestFixture 
/// class and defines the test cases for which to implement
/**
 * Class defines a testFixture in which we can testCertain
 * elements of fixtures. There are currently 5 test cases provided.
 * The elements tested are the defined shapes, circle, triangle, and
 * square. 
 * They are listed as follows: Testing for X value being too low
 * 							   Testing for X Value being too high
 * 							   Testing for Y Value being too low
 *   						   Testing for Y Value being too high
**/

class SimulatorTestFixture : public CppUnit::TestFixture
{
	public:
		/// Test cases for the Shapes fixtures
		/**
		 * Initiate the testing
		**/
		CPPUNIT_TEST_SUITE(SimulatorTestFixture);
		
		/// Test if X is too low (IE, out of the display)
		CPPUNIT_TEST(testXTooLow);
		
		/// Test if X is too high (IE, out of the display)
		CPPUNIT_TEST(testXTooHigh);
		
		/// Test if Y is too low (IE, out of the display)
		CPPUNIT_TEST(testYTooLow);
		
		/// Test if Y is too high (IE, out of the display)
		CPPUNIT_TEST(testYTooHigh);
		
		/// Test if the current point is in a corner (IE, out of the
		/// display in 2 dimensions instead of 1)
		CPPUNIT_TEST(testForCorner);
		
		/// End the testing
		CPPUNIT_TEST_SUITE_END();
		
	private:
		/// Data members
		Triangle *testTriangle;
		Square *testSquare;
		Circle *testCircle;
		int displayWidth, displayHeight;
		double time;
		
	public:	
		/// Initiate and Destruction Functions
		/**
		 * Defines new shapes in the setUp function and ensures
		 * that they are deleted upon the end of the test
		**/
		void setUp();
		void tearDown();
		
		/// Test Functions
		/**
		 * Finds the minimum x value of a shape and determines if
		 * it is out of bounds
		**/
		void testXTooLow();
		
		/**
		 * Finds the maximum x value of a shape and determines if
		 * it is out of bounds
		**/
		void testXTooHigh();
		
		/**
		 * Finds the minimum y value of a shape and determines if
		 * it is out of bounds
		**/
		void testYTooLow();
		
		/**
		 * Finds the maximum y value of a shape and determines if
		 * it is out of bounds
		**/
		void testYTooHigh();
		void testForCorner();
		
		/// Boolean Tests
		/**
		 * These functions must be passed in order for the
		 * CPPUnit tests to pass
		**/
		
		/**
		 * If the maximum x value of a shape is too high, return true
		**/
		bool isXTooHigh(Shape&);
		
		/** 
		 * If the minimum x value of a shape is too low, return true
		**/	
		bool isXTooLow(Shape&);
		
		/**
		 * If the maximum y value of a shape is too high, return true
		**/
		bool isYTooHigh(Shape&);
		
		/**
		 * If the minimum y value of a shape is too low, return true
		**/
		bool isYTooLow(Shape&);
		
		/**
		 * Update the shape depending on how much is time is punched in
		 * as well as it's current speedVector
		**/
		void updateModel(double);
};
#endif
