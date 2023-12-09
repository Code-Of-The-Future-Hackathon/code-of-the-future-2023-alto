#include "Hospital.h"


Hospital::Hospital(int patients, int area, float effectivity) :
	patients(patients),
	area(area),
	effectivity(effectivity) {}

Hospital::Hospital(){}

int Hospital::GetPatients() {
	return patients;
}
int Hospital::GetArea() {
	return area;
}
float Hospital::GetEffectivity() {
	return effectivity;
}
