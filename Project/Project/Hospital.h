#pragma once

#include <iostream>
#include "raylib.h"
#include <memory>
#include <vector>

class Hospital {
public:

	int GetPeopleSaved();
	double GetPowerSaved();
	double MoneySaved();

	void SetPeopleSaved(int value);
	void SetPowerSaved(double value);
	void SetMoneySaved(double value);

private:
	int peopleSaved = 0;
	double powerSaved = 0;
	double moneySaved = 0;
};
