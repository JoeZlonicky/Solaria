#include "RandomGenerator.h"
#include <time.h>
#include <stdlib.h>

// Seed the random generation
void RandomGenerator::init() {
	srand((unsigned int)time(NULL));
}

// Generate a random integer between two integers (inclusive)
int RandomGenerator::randint(int min, int max) {
	return min + rand() % ((max + 1) - min);
}

// Generate a random double between two doubles (inclusive)
double RandomGenerator::randdouble(double min, double max) {
	return (max - min) * ((double)rand() / (double)RAND_MAX) + min;
}