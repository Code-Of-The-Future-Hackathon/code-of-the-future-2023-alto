#include "Results.h"
#include "Manager.h"

void Results::LoadScene() { // Override for virtual LoadScene
	auto UIManager = UIManager::GetInstance();
	auto Hospital = Hospital::GetInstance();
	backgroundColor = PINK;

	Rectangle frame = { 25, 25, SCREEN_WIDTH - 50, SCREEN_HEIGHT - 50 };

	UIManager->AddRec({ frame, OFFWHITE });



	Text* temp = new Text(std::to_string(Hospital->GetPatients()), 40, {10, 10}, BLACK);
	UIManager->AddText(temp);

}

void Results::LoadText() {}