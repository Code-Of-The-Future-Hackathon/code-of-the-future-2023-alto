#pragma once
#include "Macro.h"
#include <iostream>
#include "raylib.h"
#include <string>
#include <vector>
#include <map>
#include <functional>

class Text {
public:


	Text(std::string text, int textSize, Vector2 textPos, Color textColor);

	void Draw();

	int GetTextSize();

	void SetText(std::string newText);




private:

	std::function<void()> updateLambda;
	std::string text;
	int textSize;
	Color textColor;
	Vector2 textPos;
};
