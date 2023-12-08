#include "Text.h"

Text::Text(std::string text, int textSize, Vector2 textPos, Color textColor) { // Initialize Text constructor
	this->text = text;
	this->textSize = textSize;
	this->textPos = textPos;
	this->textColor = textColor;
}

void Text::Draw() { // Draws text
	DrawText(text.c_str(), textPos.x, textPos.y, textSize, textColor);
}

int Text::GetTextSize() { // Gets text font size
	return MeasureText(text.c_str(), textSize);
}

void Text::SetText(std::string newText) { // Changes the text to a new text
	this->text = newText;
}