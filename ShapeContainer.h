// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #2
 * Shape Class Interface
 * Professor: Robert  Benkoczi
 * Program Name: ShapeContainer.h
 * Software Used: Geany
*/
#ifndef __SHAPECONTAINER_H
#define __SHAPECONTAINER_H

#include "Shape.h"
#include <string>
#include <list>

/// Class that initializes a Triangle object and allows for 
/// drawing
/**
 * Class utilizes the idea of polymorphism and uses a container of
 * oject pointers to be able to store all the children of the parent
 * of shape. It also gives appropiate methods for drawing and 
 * randomly translating them across the allegro screen
**/
class ShapeContainer
{
	private:
		// Primary container
		//std::list<Shape*> shList;
	public:
		/// Constructor
		/**
		 * Constructor ensures an empty list
		**/
		ShapeContainer();
		
		/// Destructor
		/**
		 * Deallocates all memory allocated on the heap and clears
		 * the list
		 * 
		**/
		~ShapeContainer();
		
		/// Inserter Function
		/**
		 * Function allows for the inserting of any shape into the
		 * Shape* list. Allocates the memory required (on the heap).
		 * Depending on the shape type given (as defined by the string
		 * given) it allocates the appropiate shape and inserts it.
		 * Since the number of triangles was supposed to be random, it
		 * inserts a random number of triangles into the list (between
		 * 3 and 10).
		**/
		void insert(std::string, double, double, double, double);
		
		/// Primary Draw Function
		/**
		 * Iterates through the list and calls the draw function
		 * correlated to each different shape.
		**/
		void draw();
		
		/// Random Translation Function
		/**
		 * Function creates a random Vector for each shape and moves
		 * each shape's origin to that location so that when redrawn,
		 * the shape will appear in accordance to it's origin location
		**/
		void randomTranslate();
		
		/// Deletes all the shapes in the container
		/**
		 * Iterates through the container and ensures there are no
		 * dangling pointers hanging around
		**/
		void deleteShapes();
		
		// Main list component
		std::list<Shape*> shList;
};
#endif
