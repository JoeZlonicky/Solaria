#include "Vector.h"
#include <math.h>


Vector::Vector() : Vector(0, 0) {
}

Vector::Vector(double x, double y) {
	this->x = x;
	this->y = y;
}

Vector Vector::operator-(Vector other) {
	return Vector(x - other.x, y - other.y);
}

double Vector::getLength() {
	return sqrt(x * x + y * y);
}

Vector Vector::getNormalized() {
	return Vector(x / getLength(), y / getLength());
}
