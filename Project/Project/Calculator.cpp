#include "Calculator.h"

void Calculator::LoadScene() {

	auto UIManager = UIManager::GetInstance();

	backgroundColor = PINK;
	//
	//Rectangle floorRec = { 0, SCREEN_HEIGHT - 200, SCREEN_WIDTH, 200 };
	//Rectangle borderRec = { 0, SCREEN_HEIGHT - 200 - 30, SCREEN_WIDTH, 30 };
	//UIManager->AddRec({floorRec, LIGHTPINK});
	//UIManager->AddRec({ borderRec, PINK });

	Rectangle frame = {25, 25, SCREEN_WIDTH - 50, SCREEN_HEIGHT - 50};

	UIManager->AddRec({ frame, OFFWHITE });

	int measure = MeasureText("INPUT DATA (MONTHLY)", 70);
	Text* text = new Text("INPUT DATA (MONTHLY)", 70, { (SCREEN_WIDTH - (float)measure)/2, 70 }, BLACK);
	UIManager->AddText(text);
	
	Text* patientsText = new Text("NUMBER OF PATIENTS:", 40, { 300, 200 }, BLACK);
	float posX = (350 + (float)MeasureText(patientsText->GetText().c_str(), 40));
	Input* patientsInput = new Input({ posX + 20, 190,  100, 60 }, 35, PINK, BLACK, 1, 4, []() {});

	UIManager->AddText(patientsText);
	UIManager->AddInput(patientsInput);


	Text* areaText = new Text("AREA (SQUARED M):", 40, { 300, 325 }, BLACK);
	Input* areaInput = new Input({ posX + 20, 315,  100, 60 }, 35, PINK, BLACK, 1, 4, []() {});

	UIManager->AddText(areaText);
	UIManager->AddInput(areaInput);

	Text* effText = new Text("PANEL EFFICIENCY(%):", 40, { 300, 450 }, BLACK);
	Input* effInput = new Input({ posX + 20, 440,  100, 60 }, 35, PINK, BLACK, 1, 4, []() {});

	UIManager->AddText(effText);
	UIManager->AddInput(effInput);

	std::shared_ptr<Button> calculate = std::make_shared<Button>(Rectangle{ (SCREEN_WIDTH - 300) / 2, 550, 300, 80 }, "CALCULATE", 40, PINK, BLACK,
		[]() {});

	calculate->SetLambda([patientsInput, areaInput, effInput, UIManager, calculate]() {
		if (!(patientsInput->GetInputString().empty()
			|| areaInput->GetInputString().empty()
			|| effInput->GetInputString().empty()
			))
		{
			Hospital::GetInstance()->Init(
				std::stoi(patientsInput->GetInputString()),
				std::stoi(areaInput->GetInputString()),
				(float)std::stoi(effInput->GetInputString())
			);

			SceneManager::GetInstance()->ChangeScene("Results");
		}
		else
		{
			calculate->SetText("INPUT ALL");
		}
	});
	UIManager->AddButton(calculate);

}

void Calculator::LoadText() {}