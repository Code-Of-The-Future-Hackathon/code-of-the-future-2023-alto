#include "Results.h"
#include "Manager.h"

void Results::LoadScene() { // Override for virtual LoadScene
	auto UIManager = UIManager::GetInstance();
	auto Hospital = Hospital::GetInstance();
	backgroundColor = PINK;

	Rectangle frame = { 25, 25, SCREEN_WIDTH - 50, SCREEN_HEIGHT - 50 };

	UIManager->AddRec({ frame, OFFWHITE });

	Text* results = new Text("Results", 50, {(SCREEN_WIDTH - (float)MeasureText("Results", 50)) / 2, 50}, BLACK);
	UIManager->AddText(results);

	float surgeryConsumption = 0;
	for (int i = 0; i < Hospital->GetPatients(); i++) {
		SetRandomSeed(GetTime());
		surgeryConsumption += GetRandomValue(MIN_SURGERY_CONSUMPTION, MAX_SURGERY_CONSUMPTION);
	}

	float energyGeneration = 0;
	for (int i = 0; i < 30; i++) {
		SetRandomSeed(GetTime());
		energyGeneration += GetRandomValue(MIN_PANEL_OUTPUT, MAX_PANEL_OUTPUT) * Hospital->GetArea() * (Hospital->GetEffectivity() / 100);
	}
	std::string surgeryConsumptionString = "Patient power consumption: " + std::to_string((int)surgeryConsumption) + " KWH";
	Text* surgeryConsumptionText = new Text(surgeryConsumptionString, 40, {(float)(SCREEN_WIDTH - MeasureText(surgeryConsumptionString.c_str(), 40))/2, 150}, BLACK);
	UIManager->AddText(surgeryConsumptionText);

	std::string energyGenerationString = "Panel power generation: " + std::to_string((int)energyGeneration) + " KWH";
	Text* energyGenerationText = new Text(energyGenerationString, 40, { (float)(SCREEN_WIDTH - MeasureText(energyGenerationString.c_str(), 40)) / 2, 210 }, BLACK);
	UIManager->AddText(energyGenerationText);

	std::string panelPriceString = "Total panel price: $" + std::to_string((int)Hospital->GetArea()*AVG_PANEL_COST);
	Text* panelPriceText = new Text(panelPriceString, 40, { (float)(SCREEN_WIDTH - MeasureText(panelPriceString.c_str(), 40)) / 2, 270 }, BLACK);
	UIManager->AddText(panelPriceText);

	std::string compareString1;
	std::string compareString2;
	if (energyGeneration > surgeryConsumption) {
		compareString1 = "Panel generation will be enough.";
		compareString2 = "Remaining power : " + std::to_string((int)(energyGeneration - surgeryConsumption)) + " KWH";
	}
	if (energyGeneration == surgeryConsumption) {
		compareString1 = "Panel generation will be exactly enough.";

	}
	if (energyGeneration < surgeryConsumption) {
		compareString1 = "Panel generation will not be enough.";
		compareString2 = "Additional power needed : " + std::to_string((int)(surgeryConsumption-energyGeneration)) + " KWH";
	}

	Text* compareText1 = new Text(compareString1, 40, { (float)(SCREEN_WIDTH - MeasureText(compareString1.c_str(), 40)) / 2, 330 }, BLACK);
	UIManager->AddText(compareText1);
	if (energyGeneration != surgeryConsumption) {
		Text* compareText2 = new Text(compareString2, 40, { (float)(SCREEN_WIDTH - MeasureText(compareString2.c_str(), 40)) / 2, 390 }, BLACK);
		UIManager->AddText(compareText2);
	}


	//Text* temp = new Text(std::to_string(Hospital->GetPatients()), 40, {10, 10}, BLACK);
	//UIManager->AddText(temp);

}

void Results::LoadText() {}