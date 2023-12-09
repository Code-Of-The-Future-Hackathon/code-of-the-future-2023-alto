#include "MainMenu.h"
#include "Manager.h"

void MainMenu::LoadScene() { // Override for virtual LoadScene
	auto UIManager = UIManager::GetInstance();

	backgroundColor = OFFWHITE;

	UIManager->AddText(new Text({ "ALTO", 100, {200, 100}, BLACK }));

	Image logoImg = LoadImage("../assets/logo.png");
	ImageResize(&logoImg, 500, 500);
	Texture2D logoTx = LoadTextureFromImage(logoImg);
	UIManager->AddTexture({ logoTx, {0,0, 500, 500}, {SCREEN_WIDTH - 600, SCREEN_HEIGHT - 600 } });

	float buttonX = 200.0f + (MeasureText("ALTO", 100) - 200) / 2;

	UIManager->AddButton({ {buttonX, 275, 200, 75}, "DEMO", 30, LIGHTPINK, BLACK, []() {
		SceneManager::GetInstance()->ChangeScene("Demo");
	} });

	UIManager->AddButton({ {buttonX, 400, 200, 75}, "QUIT", 30, LIGHTPINK, BLACK, []() {
		Manager::GetInstance()->Close();
} });

	CheckButton* fullScreen = new CheckButton({ buttonX - 50,  550, 300, 75 }, "FULLSCREEN", 30, LIGHTPINK, WHITE, BLACK,
		[UIManager]() {
			UIManager->ToggleFullScreen();
		}, UIManager->GetShouldFullscreen(), 1);
	UIManager->AddCheckButton(fullScreen);

}

void MainMenu::LoadText() {}