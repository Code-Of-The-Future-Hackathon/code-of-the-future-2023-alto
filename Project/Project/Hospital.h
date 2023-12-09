#pragma once

#include <iostream>
#include "raylib.h"
#include <memory>
#include <vector>

class Hospital {
public:

	static std::shared_ptr<Hospital> GetInstance() {
		if (instance == nullptr) {
			instance = std::make_shared<Hospital>();
		}
		return instance;
	}

	void Init(int patients, int area, float effectivity);

	int GetPatients();
	int GetArea();
	float GetEffectivity();

private:
	static std::shared_ptr<Hospital> instance;
	int patients;
	int area;
	float effectivity;

};
