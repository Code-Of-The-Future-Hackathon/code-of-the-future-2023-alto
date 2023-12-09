#include "Input.h"
//input.h
Input::Input(Rectangle body, int textSize, Color bodyColor, Color textColor, int minInputSize, int maxInputSize, std::function<void()> lambda) // Initialize input constructor
{
	this->body = body;
	this->textSize = textSize;
	this->bodyColor = bodyColor;
	this->textColor = textColor;
	this->lambda = lambda;
	this->bodyColorSecondary = { bodyColor.r /= 3, bodyColor.g /= 3, bodyColor.b /= 3, 80 };
	this->maxInputSize = maxInputSize;
	this->minInputSize = minInputSize;
}
bool Input::IsHovered() // Check if user is hovering over input body
{
	return (CheckCollisionPointRec(GetMousePosition(), body));
}

void Input::Draw() { // Draws input field
	if (IsHovered() || isSelected || !canInput)
	{
		DrawRectangleRec(body, bodyColorSecondary);
	}
	else {
		DrawRectangleRec(body, bodyColor);
	}
	int textX = body.x + (body.width - MeasureText(inputString.c_str(), textSize)) / 2;
	int textY = body.y + (body.height - textSize) / 2;
	if (inputString.size() != 0)
		DrawText(inputString.c_str(), textX, textY, textSize, textColor);
	DrawBorder();
}

void Input::DrawBorder() { // Draws input field border
	int offset = 4;
	int thickness = 4;
	Rectangle border = body;
	border.width += offset;
	border.height += offset;
	if (isSelected) {
		if (!canInput)
			DrawRectangleLinesEx(border, thickness, BLACK);
		else
			DrawRectangleLinesEx(border, thickness, GRAY);
	}
	if (!isSelected)
		DrawRectangleLinesEx(border, thickness, BLACK);
}

void Input::Update() {
	Select();
	AddChar();
}

void Input::Select() { // Selects input field if user clicks on input body
	if (IsMouseButtonPressed(0)) {
		this->isSelected = (CheckCollisionPointRec(GetMousePosition(), body));
	}
}

bool Input::IsSelected() {
	return isSelected;
}

void Input::AddChar() { // Adds character to input string
	if (isSelected && canInput) {
		int key = GetKeyPressed();

		if (key != KEY_BACKSPACE && key >= 33 && key <= 122) {
			if (inputString.size() < maxInputSize) {
				inputString.push_back((char)key);
			}
		}
		if (key == KEY_BACKSPACE) {
			if (inputString.size() > 0) {
				inputString.pop_back();
			}
		}
	}
}

std::string Input::GetInputString() {
	return inputString;
}

void Input::SetInputString(std::string str) {
	inputString = str;
}

void Input::CallLambda() {
	lambda();
}

void Input::ToggleCanInput() {
	this->canInput = !canInput;
}