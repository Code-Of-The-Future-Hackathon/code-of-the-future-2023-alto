#include "UIManager.h"

std::shared_ptr<UIManager> UIManager::instance = nullptr;

void UIManager::AddButton(Button button) {
	this->buttonList.push_back(button);
}

void UIManager::AddCheckButton(CheckButton* checkButton) {
	this->checkButtonList.push_back(checkButton);
}

void UIManager::AddInput(Input* input) {
	this->intputList.push_back(input);
}



void UIManager::AddText(Text* text) {
	this->textList.push_back(text);
}

void UIManager::AddRec(RectangleV2 rec) {
	this->rectangleList.push_back(rec);
}

void UIManager::AddTexture(TextureV texture) {
	this->textureList.push_back(texture);
}

void UIManager::AddQuestion(Question* question) {
	this->questionList.push_back(question);
}


void UIManager::UpdateAll() { // Updates all members of all lists 
	for (auto button : buttonList) {
		button.Update();
	}
	for (auto checkButton : checkButtonList) {
		checkButton->Update();
	}
	for (auto input : intputList) {
		input->Update();
	}
	for (auto question : questionList) {
		question->Update();
	}
}

void UIManager::DrawAll() { // Draws all members from all lists
	for (const auto& rec : rectangleList) {
		DrawRectangleRec(rec.rec, rec.recColor);
	}
	for (const auto& texture : textureList) {
		DrawTextureRec(texture.texture, texture.frameRec, texture.pos, WHITE);
	}
	for (Button button : buttonList) {
		button.Draw();
	}
	for (CheckButton* checkButton : checkButtonList) {
		checkButton->Draw();
	}
	for (Text* text : textList) {
		text->Draw();
	}
	for (Input* input : intputList) {
		input->Draw();
	}

	for (Question* question : questionList) {
		question->Draw();
	}
}

void UIManager::UpdateLists() { // Clears all elements from all lists
	buttonList.clear();
	textList.clear();
	checkButtonList.clear();
	rectangleList.clear();
	textureList.clear();
	intputList.clear();
	questionList.clear();
}

void UIManager::ToggleFPS() {
	this->shouldFpsShow = !this->shouldFpsShow;
}

void UIManager::ToggleFullScreen() {
	ToggleFullscreen();
	shouldFullscreen = !shouldFullscreen;
}


bool UIManager::GetShouldFpsShow() {
	return this->shouldFpsShow;
}

bool UIManager::GetShouldFullscreen() {
	return this->shouldFullscreen;
}


std::vector<Text*> UIManager::GetTextList() { // Returns text list
	return this->textList;
}