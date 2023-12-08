#pragma once
#include "Macro.h"
#include <iostream>
#include "raylib.h"
#include <string>
#include <vector>
#include <map>
#include <functional>

class CheckButton {
public:

	// Declare constructor for CheckButton
	CheckButton(Rectangle body, std::string text, int textSize, Color mainBodyColor, Color checkBoxBodyColor, Color textColor, std::function<void()> lambda, bool isChecked, bool execLambdaIfClicked = 0);

	void Draw(); // Function for drawing check button

	void DrawBorder(); // Function for drawing check button border

	bool IsClicked(); // Checks if user has clicked on check button box

	void Update();
private:
	bool execLambdaIfClicked;
	bool isChecked;
	std::function<void()> lambda;
	Rectangle mainBody;
	Rectangle checkBoxBody;
	std::string text;
	int textSize;
	Color mainBodyColor, textColor, checkBoxBodyColor;
};
