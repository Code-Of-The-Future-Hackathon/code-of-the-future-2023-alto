#include "Hospital.h"

int Hospital::GetPeopleSaved() {
	return peopleSaved;
}
double Hospital::GetPowerSaved() {
	return powerSaved;
}
double Hospital::MoneySaved() {
	return moneySaved;
}

void Hospital::SetPeopleSaved(int value) {
	peopleSaved = value;
}
void Hospital::SetPowerSaved(double value) {
	powerSaved = value;
}
void Hospital::SetMoneySaved(double value) {
	moneySaved = value;
}