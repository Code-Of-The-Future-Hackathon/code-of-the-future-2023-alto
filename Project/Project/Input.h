#pragma once
#include "Macro.h"
#include <iostream>
#include "raylib.h"
#include <string>
#include <vector>
#include <map>
#include <functional>


class Input {
public:
	Input(Rectangle body, int textSize, Color bodyColor, Color textColor, int minInputSize, int maxInputSize, std::function<void()> lambda);

	void Draw(); // Function to draw input

	void DrawBorder(); // Function to draw input border

	bool IsSelected();

	void Select(); // Selects input field

	void AddChar(); // Adds character to inputed text

	bool IsHovered();

	void Update();

	void CallLambda();

	void ToggleCanInput();

	std::string GetInputString();

	void SetInputString(std::string str);

private:
	bool canInput = 1; // Permission to input

	int maxInputSize;
	int minInputSize;

	std::string inputString;

	bool isSelected = 0;
	std::function<void()> lambda;
	Rectangle body;
	int textSize;
	Color bodyColor, textColor, bodyColorSecondary;
};

