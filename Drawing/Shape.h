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
	unsigned int currentColor;
	float x, y;
	ShapeEnum shape;
};

// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{
public:
	virtual void draw(RenderWindow& win) = 0;
	virtual ShapeInfo getRecordInfo() = 0;
};

// add Circle, Square classes below. These are derived from DrawingShape
class Circle : public DrawingShape
{
private:
	CircleShape circ;
public:
	// Default Constructor
	Circle(Vector2f pos, Color color)
	{
		circ.setPosition(pos);
		circ.setFillColor(color);
		circ.setRadius(5);
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

	ShapeInfo getRecordInfo()
	{
		return { circ.getFillColor().toInteger(), circ.getPosition().x, circ.getPosition().y, CIRCLE };
	}
};

class Square : public DrawingShape
{
private:
	RectangleShape rect;
public:
	// Default Constructor
	Square(Vector2f pos, Color color)
	{
		rect.setPosition(pos);
		rect.setFillColor(color);
		rect.setSize(Vector2f(10, 10));
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

	// Function: getRecordInfo, returns a ShapeInfo object to write to the file
	// Parameters: none
	// Return: ShapeInfo object containing info of shape to be written to file
	ShapeInfo getRecordInfo()
	{
		return { rect.getFillColor().toInteger(), rect.getPosition().x, rect.getPosition().y, SQUARE };
	}
};


