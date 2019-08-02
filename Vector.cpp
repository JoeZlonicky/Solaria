#include "Vector.h"
#include <math.h>


// Create a basic vector of x = 0, y = 0
Vector::Vector() : Vector(0, 0) {
}

// Create a vector of certain dimensions
Vector::Vector(double x, double y) {
	this->x = x;
	this->y = y;
}

// Get the subtraction of two vectors by the difference of each component
Vector Vector::operator-(Vector other) {
	return Vector(x - other.x, y - other.y);
}

// Get the length of a vector using pythagoras
double Vector::getLength() {
	return sqrt(x * x + y * y);
}

// Get the normalized vector (vector with same ratio where length is 1)
Vector Vector::getNormalized() {
	return Vector(x / getLength(), y / getLength());
}
