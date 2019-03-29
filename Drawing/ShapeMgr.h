#pragma once
//=============================================================================
// Austin Kemp
// 29 March 2019
// Description: Class that maintains and updates the list of DrawingShapes
//=============================================================================
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

class ShapeMgr
{
private:
	vector <DrawingShape*> shapes;
public:
	// Default Constructor
	ShapeMgr()
	{
		shapes = { };
	}

	// Function: addShape, adds a shape to the vector of DrawingShape pointers
	// Parameters: pos, Vector2f object containing the position of the shape
	// whichShape: ShapeEnum object that contains if its a square or circle
	// color: Color object containing the color of the shape
	// Return: none
	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		if (whichShape == CIRCLE)
		{
			CircleShape circ;
			circ.setPosition(pos);
			circ.setRadius(10);
			circ.setFillColor(color);
			Circle newCirc(circ);
			shapes.push_back(&newCirc);
		}
		else if (whichShape == SQUARE)
		{
			RectangleShape rect;
			rect.setPosition(pos);
			rect.setSize(Vector2f(20, 20));
			rect.setFillColor(color);
			Square newRect(rect);
			shapes.push_back(&newRect);
		}
	}

	// Function: getShapes, gets the vector of pointers to DrawingShapes
	// for the DrawingUI class
	// Parameters: none
	// Return: shapes, constant vector of pointers to DrawingShapes that has
	// all of the shapes drawn
	const vector <DrawingShape*> getShapes()
	{
		return shapes;
	}

};
