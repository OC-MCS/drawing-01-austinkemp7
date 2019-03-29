#pragma once
//=============================================================================
// Austin Kemp
// 29 March 2019
// Description: File containing a structure to read the shapes to a file and
// classes to create squares and circles
//=============================================================================
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

struct ShapeInfo
{
	Color currentColor;
	//DrawingShape currentShape;
	ShapeEnum shape;
};

// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{
public:
	void draw(RenderWindow);
	ShapeInfo getRecordInfo();
};

// add Circle, Square classes below. These are derived from DrawingShape
class Circle : public DrawingShape
{
private:
	CircleShape circ;
public:
	// Default Constructor
	Circle(CircleShape newCirc)
	{
		circ = newCirc;
	}
	// Function: draw, draws the circle object on the screen
	// Parameters:
	// win: reference to RenderWindow object that serves as a target for a 2D 
	// drawing
	// Return: none
	void draw(RenderWindow &win)
	{
		win.draw(circ);
	}
};

class Square : public DrawingShape
{
private:
	RectangleShape rect;
public:
	Square(RectangleShape newRect)
	{
		rect = newRect;
	}
	// Function: draw, draws the square object on the screen
	// Parameters:
	// win: reference to RenderWindow object that serves as a target for a 2D 
	// drawing
	// Return: none
	void draw(RenderWindow &win)
	{
		win.draw(rect);
	}
};


