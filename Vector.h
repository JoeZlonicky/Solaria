#pragma once

struct Vector {
	Vector();
	Vector(double x, double y);

	Vector operator-(Vector other);
	double getLength();
	Vector getNormalized();

	double x;
	double y;
};