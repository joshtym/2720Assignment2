// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #2
 * Main Program
 * Professor: Robert  Benkoczi
 * Program Name: mainTest.cc
 * Software Used: Geany
*/

#include "SimulatorTestFixture.h"
#include <cppunit/ui/text/TestRunner.h>

/// Function Prototype: drawDisplay
/**
 * Purpose: Simple function to display the contents drawn
 *          by Allegro
**/
//void drawDisplay(ShapeContainer&);

int main(void)
{
	/// Main CPP runner testing unit. As the famous GLADoS would say,
	/// "Let us begin testing, for science."
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(SimulatorTestFixture::suite());
	runner.run();
	
	return 0;
}

/// Function definition
/*void drawDisplay(ShapeContainer& shapes)
{
	// Create a 800x600 window
	Display disp;
	
	// Draw the shapes
	shapes.draw();
	
	// Display the shapes
	al_flip_display();
	
	// Keep the display up for 4 seconds
	al_rest(4.0);
}*/

