#pragma once
//=============================================================================
// Austin Kemp
// 29 March 2019
// Description: Class that maintains the current settings of the shape and
// color
//=============================================================================
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

class SettingsMgr
{
private:
	Color curColor;
	ShapeEnum curShape;
public:
	// Default Constructor
	SettingsMgr(Color startingColor, ShapeEnum startingShape)
	{
		curColor = startingColor;
		curShape = startingShape;
	}

	// Function: getCurColor, returns the current color being used to draw
	// Parameters: none
	// Return: curColor, current color selected
	Color getCurColor()
	{
		return curColor;
	}

	// Function: setCurColor, changes the current color being used to draw
	// Parameters:
	// newColor: the new color wanting to be used
	// Return: none
	void setCurColor(Color newColor)
	{
		curColor = newColor;
	}

	// Function: getCurShape, returns current shape being used to draw
	// Parameters: none
	// Return: curShape, ShapeEnum containing the current shape being used
	ShapeEnum getCurShape()
	{
		return curShape;
	}

	// Function: setShape, changes current shape being used to draw
	// Parameters:
	// newShape: ShapeEnum object that the user wants to use
	// Return: none
	void setShape(ShapeEnum newShape)
	{
		curShape = newShape;
	}

	// Function: readFromFile, reads the color and shape settings from the file
	// Parameters:
	// file: reference to an fstream object to read to
	// Return: none
	void readFromFile(fstream& file)
	{
		unsigned int colorSetting;
		file.read(reinterpret_cast<char*>(&colorSetting), sizeof(unsigned int));
		file.read(reinterpret_cast<char*>(&curShape), sizeof(ShapeEnum));
		curColor = Color(colorSetting);
	}

	// Function: writeFromFile, writes the color and shape settings from the
	// file
	// Parameters:
	// file: reference to an fstream object to write to
	// Return: none
	void writeToFile(fstream& file)
	{
		unsigned int colorSetting = curColor.toInteger();
		file.write(reinterpret_cast<char*>(&colorSetting), sizeof(unsigned int));
		file.read(reinterpret_cast<char*>(&curShape), sizeof(ShapeEnum));
	}
};
