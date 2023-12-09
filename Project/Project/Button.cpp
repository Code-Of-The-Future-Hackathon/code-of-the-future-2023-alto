#include "Button.h"

Button::Button(Rectangle body, std::string text, int textSize, Color bodyColor, Color textColor, std::function<void()> lambda)
{
	this->body = body;
	this->text = text;
	this->textSize = textSize;
	this->bodyColor = bodyColor;
	this->textColor = textColor;
	this->lambda = lambda;
	this->bodyColorSecondary = { bodyColor.r /= 3, bodyColor.g /= 3, bodyColor.b /= 3, 80 };
}
bool Button::IsHovered()
{
	return (CheckCollisionPointRec(GetMousePosition(), body));
}
void Button::Draw() {
	if (IsHovered() || !canClick)
	{
		DrawRectangleRec(body, bodyColorSecondary);
	}
	else {
		DrawRectangleRec(body, bodyColor);
	}
	DrawBorder();
	int textX = body.x + (body.width - MeasureText(text.c_str(), textSize)) / 2;
	int textY = body.y + (body.height - textSize) / 2;
	DrawText(text.c_str(), textX, textY, textSize, textColor);
}

void Button::DrawBorder() {
	int offset = 4;
	int thickness = 4;
	Rectangle border = body;
	border.width += offset;
	border.height += offset;

	DrawRectangleLinesEx(border, thickness, BLACK);
}

void Button::Update() {
	if (canClick) {
		if (IsClicked())
			lambda();
	}
}

bool Button::IsClicked() {
	return (IsMouseButtonPressed(0) && CheckCollisionPointRec(GetMousePosition(), body));
}

void Button::ToggleClicking() {
	this->canClick = !canClick;
}

void Button::SetLambda(std::function<void()> lambda) {
	this->lambda = lambda;
}

void Button::SetText(std::string text) {
	this->text = text;
}