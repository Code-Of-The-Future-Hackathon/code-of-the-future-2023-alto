#pragma once
#include "Macro.h"
#include <iostream>
#include "raylib.h"
#include "Text.h"
#include "Input.h"
#include <string>
#include <vector>
#include <map>
#include <functional>
#include "Button.h"

class Question {
public:

	Question(Text* question, std::string answer, Button* check, Input* answerField, int textSize);

	void Draw();

	void Update();

private:

	Text* question;
	std::string answer;
	Button* check;
	Input* answerField;

	bool isChecked = 0;
	int textSize;

};
