#include "RandomGenerator.h"
#include <time.h>
#include <stdlib.h>

void RandomGenerator::init() {
	srand((unsigned int)time(NULL));
}

int RandomGenerator::randint(int min, int max) {
	return min + rand() % ((max + 1) - min);
}

double RandomGenerator::randdouble(double min, double max) {
	return (max - min) * ((double)rand() / (double)RAND_MAX) + min;
}