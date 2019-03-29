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
			shapes.push_back(new Circle(pos, color));
		}
		else if (whichShape == SQUARE)
		{
			shapes.push_back(new Square(pos, color));
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

	// Function: readFromFile, reads the shapes from the file
	// Parameters:
	// file: reference to an fstream object to read to
	// Return: none
	void readFromFile(fstream &file)
	{
		ShapeInfo insideShape;
		while (file.read(reinterpret_cast<char*>(&insideShape), sizeof(insideShape)));
			addShape(Vector2f(insideShape.x, insideShape.y), insideShape.shape, Color(insideShape.currentColor));
	}

	// Function: writeFromFile, writes shapes to the file
	// Parameters:
	// file: reference to an fstream object to write to
	// Return: none
	void writeToFile(fstream &file)
	{
		for (int i = 0; i < shapes.size(); i++)
		{
			file.write(reinterpret_cast<char*>(&shapes[i]->getRecordInfo()), sizeof(ShapeInfo));
		}
	}
};
