#pragma once
#include "Macro.h"
#include <iostream>
#include "raylib.h"
#include <string>
#include <vector>
#include <map>
#include <functional>


class Button {
public:
	Button(Rectangle body, std::string text, int textSize, Color bodyColor, Color textColor, std::function<void()> lambda); // Declare Button constructor

	void Draw(); // Function used for drawing button

	void DrawBorder(); // Function used for drawing button border

	bool IsClicked(); // Checks if user has clicked on button

	bool IsHovered(); // Checks if user is hovering over button with mouse

	void Update();

	void ToggleClicking(); // Toggles permission to click on button

private:

	bool canClick = 1; // Permission to click on button
	std::function<void()> lambda;
	Rectangle body; // Button body
	std::string text; // Button text
	int textSize; // Button text font size
	Color bodyColor, textColor, bodyColorSecondary;
};
