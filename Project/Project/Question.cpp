#include "Question.h"
#include "UIManager.h"

Question::Question(Text* question, std::string answer, Button* check, Input* answerField, int textSize) { // Initialize Question constructor
	this->question = question;
	this->answer = answer;
	this->check = check;
	this->answerField = answerField;
}

void Question::Draw() { // Draws all elements in question
	question->Draw();
	check->Draw();
	answerField->Draw();
}

void Question::Update() { // Updates button and input in question
	check->Update();
	answerField->Update();
}