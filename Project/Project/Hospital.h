#pragma once

#include <iostream>
#include "raylib.h"
#include <memory>
#include <vector>

class Hospital {
public:

	Hospital(int patients, int area, float effectivity);
	Hospital();

	int GetPatients();
	int GetArea();
	float GetEffectivity();

private:
	int patients;
	int area;
	float effectivity;

};
