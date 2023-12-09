#include "Game.h"

void Game::LoadScene() {

	auto UIManager = UIManager::GetInstance();

	backgroundColor = SKYBLUE;
	
	Rectangle floorRec = { 0, SCREEN_HEIGHT - 200, SCREEN_WIDTH, 200 };
	Rectangle borderRec = { 0, SCREEN_HEIGHT - 200 - 30, SCREEN_WIDTH, 30 };
	UIManager->AddRec({floorRec, GRAY});
	UIManager->AddRec({ borderRec, DARKGRAY });

	Rectangle hospitalInfo = {25, 25, 350, SCREEN_HEIGHT - 50};

	UIManager->AddRec({ hospitalInfo, OFFWHITE });
}

void Game::LoadText() {}