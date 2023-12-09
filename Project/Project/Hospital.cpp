#include "Hospital.h"

std::shared_ptr<Hospital> Hospital::instance = nullptr;

int Hospital::GetPatients() {
	return patients;
}
int Hospital::GetArea() {
	return area;
}
float Hospital::GetEffectivity() {
	return effectivity;
}

void Hospital::Init(int patients, int area, float effectivity) {
	this->patients = patients;
	this->area = area;
	this->effectivity = effectivity;
}