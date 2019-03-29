#pragma once
//=============================================================================
// Austin Kemp
// 29 March 2019
// Description: Class that handles all the user interface associated with
// drawing shapes on the screen
//=============================================================================
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"


class DrawingUI
{
private:
	Vector2f p2;
public:
	// Default Constructor
	DrawingUI(Vector2f p)
	{
		p = p2;
	}

	// Function: draw, uses a pointer to a list of DrawingShapes to
	// draw the shapes on the canvas
	// Parameters: 
	// win: reference to RenderWindow object that serves as a target for a 2D
	// drawing
	// mgr: pointer to a ShapeMgr object holding the list of shapes
	// Return: none
	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		vector <DrawingShape*> shapes = mgr->getShapes();
	}
	
	// Function: isMouseInCanvas, checks if mouse is within bounds of canvas
	// Parameters:
	// mousePos: Vector2f object containing the position of the mouse
	// Return: bool, represents if mouse is in the canvas or not
	bool isMouseInCanvas(Vector2f mousePos)
	{
		return false; // just to make it compile
	}



};

