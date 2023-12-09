#include "MainMenu.h"
#include "Manager.h"

void MainMenu::LoadScene() { // Override for virtual LoadScene
	auto UIManager = UIManager::GetInstance();

	Image logoImg = LoadImage("../assets/AlTo logo.png");
	ImageResize(&logoImg, 500, 500);
	Texture2D logoTx = LoadTextureFromImage(logoImg);
	UIManager->AddTexture({ logoTx, {0,0, 500, 500}, {SCREEN_WIDTH - 600, SCREEN_HEIGHT - 600 } });

	float buttonX = 200.0f + (MeasureText("ALTO", 100) - 200) / 2;

	//UIManager->AddButton({ {(SCREEN_WIDTH - 300) / 2 - 160,  200, 300, 100}, "PLAY", 50, LIGHTPINK, BLACK, []() {
	//	SceneManager::GetInstance()->ChangeScene("Play");
	//} });

	UIManager->AddButton({ {buttonX, 275, 200, 75}, "PLAY", 30, LIGHTPINK, BLACK, []() {
		SceneManager::GetInstance()->ChangeScene("Play");
	} });

	UIManager->AddButton({ {buttonX, 400, 200, 75}, "SETTINGS", 30, LIGHTPINK, BLACK, []() {
	SceneManager::GetInstance()->ChangeScene("Settings");
} });

	UIManager->AddButton({ {buttonX, 525, 200, 75}, "QUIT", 30, LIGHTPINK, BLACK, []() {
		Manager::GetInstance()->Close();
} });

	//UIManager->AddButton({ {(SCREEN_WIDTH - 300) / 2 + 200, 200, 300, 100}, "SETTINGS", 50, LIGHTPINK, BLACK, []() {
	//	SceneManager::GetInstance()->ChangeScene("Settings");
	//} });

	//UIManager->AddButton({ {(SCREEN_WIDTH - 300) / 2, 380, 300, 100}, "QUIT", 50, LIGHTPINK, BLACK, []() {
	//	Manager::GetInstance()->Close();
	//} });

	UIManager->AddText(new Text({ "ALTO", 100, {200, 100}, BLACK }));

	backgroundColor = OFFWHITE;

}

void MainMenu::LoadText() {}