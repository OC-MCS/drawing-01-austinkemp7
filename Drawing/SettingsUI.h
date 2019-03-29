#pragma once
//=============================================================================
// Austin Kemp
// 29 March 2019
// Description: Class that displays and handles all the user interface with the
// menu
//=============================================================================
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"


class SettingsUI
{
private:
	CircleShape redBtn;
	CircleShape greenBtn;
	CircleShape blueBtn;
	CircleShape circleBtn;
	RectangleShape squareBtn;
	SettingsMgr *manager;
public:
	// Function: die, a utility function to call anytime we need to quit
	// the program
	// Parameters: msg, string containing the message to display when the
	// program quits
	// Return: none
	void die(string msg)
	{
		cout << msg << endl;
		exit(-1);
	}

	// Default Constructor
	SettingsUI(SettingsMgr *mgr)
	{
		manager = mgr;
	}

	// Function: handleMouseUp, detects if the mouse is over a button and
	// sets the current color/shape to whatever the mouse hovers over
	// Parameters:
	// mouse: Vector2f object containing the mouse's position
	// Return: none
	void handleMouseUp(Vector2f mouse)
	{
		if (redBtn.getGlobalBounds().contains(mouse))
		{
			manager->setCurColor(Color::Red);
		}
		if (greenBtn.getGlobalBounds().contains(mouse))
		{
			manager->setCurColor(Color::Green);
		}
		if (blueBtn.getGlobalBounds().contains(mouse))
		{
			manager->setCurColor(Color::Blue);
		}
		if (circleBtn.getGlobalBounds().contains(mouse))
		{
			manager->setShape(ShapeEnum::CIRCLE);
		}
		if (squareBtn.getGlobalBounds().contains(mouse))
		{
			manager->setShape(ShapeEnum::SQUARE);
		}
	}

	// Function: draw, displays the labels and buttons
	// Parameters:
	// win: reference to RenderWindow object that serves as a target for a 2D
	// drawing
	// Return: none
	void draw(RenderWindow& win)
	{
		// first have to load font
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");

		// title
		Text title("Selected Color", font, 25);
		title.setPosition(30, 25);
		win.draw(title);

		Vector2f redPos(90, 80);
		redBtn.setPosition(redPos);
		redBtn.setRadius(20);
		redBtn.setOutlineThickness(2);
		redBtn.setOutlineColor(Color::Red);
		// for just an outlined button
		redBtn.setFillColor(Color::Transparent);

		// The following renders the circle on the screen
		// win is a RenderWindow (see provided code)

		Vector2f greenPos(90, 135);
		greenBtn.setPosition(greenPos);
		greenBtn.setRadius(20);
		greenBtn.setOutlineThickness(2);
		greenBtn.setOutlineColor(Color::Green);
		greenBtn.setFillColor(Color::Transparent);

		Vector2f bluePos(90, 190);
		blueBtn.setPosition(bluePos);
		blueBtn.setRadius(20);
		blueBtn.setOutlineThickness(2);
		blueBtn.setOutlineColor(Color::Blue);
		// for just an outlined button
		blueBtn.setFillColor(Color::Transparent);

		Text shapeTitle("Selected Shape", font, 25);
		shapeTitle.setPosition(30, 250);
		win.draw(shapeTitle);

		Vector2f circlePos(90, 305);
		circleBtn.setPosition(circlePos);
		circleBtn.setRadius(20);
		circleBtn.setOutlineThickness(2);
		circleBtn.setOutlineColor(Color::White);
		
		Vector2f sqPos(90, 360);
		squareBtn.setPosition(sqPos);
		squareBtn.setOutlineColor(Color::White);
		squareBtn.setOutlineThickness(2);
		squareBtn.setSize(Vector2f(40, 40));
		squareBtn.setOutlineColor(Color::White);

		Color col = manager->getCurColor();
		if (col == Color::Red)
		{
			redBtn.setFillColor(Color::Red);
		}
		else if (col == Color::Green)
		{
			greenBtn.setFillColor(Color::Green);
		}
		else if (col == Color::Blue)
		{
			blueBtn.setFillColor(Color::Blue);
		}

		win.draw(redBtn);
		win.draw(greenBtn);
		win.draw(blueBtn);

		ShapeEnum curShape = manager->getCurShape();
		if (curShape == CIRCLE)
		{
			circleBtn.setFillColor(Color::White);
		}
		else if (curShape == SQUARE)
		{
			squareBtn.setFillColor(Color::White);
		}

		win.draw(circleBtn);
		win.draw(squareBtn);



	}

};
