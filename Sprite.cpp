#include <SDL.h>
#include "Sprite.h"
#include "AssetLoader.h"


Sprite::Sprite(SDL_Texture* texture, double x, double y) {
	this->texture = texture;
	position = Vector(x, y);
	int w, h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	size = Vector(w, h);
}

Sprite::Sprite(std::string filePath, double x, double y) : Sprite(AssetLoader::LoadTexture(filePath), x, y) {
}

void Sprite::setX(double x) {
	position.x = x;
}

void Sprite::setY(double y) {
	position.y = y;
}

void Sprite::setPosition(double x, double y) {
	setX(x);
	setY(y);
}

void Sprite::setCenterX(double x) {
	position.x = x - size.x / 2;
}

void Sprite::setCenterY(double y) {
	position.y = y - size.y / 2;
}

void Sprite::setCenter(double x, double y) {
	setCenterX(x);
	setCenterY(y);
}

void Sprite::setRotation(double rotation) {
	this->rotation = rotation;
}

void Sprite::setFlip(SDL_RendererFlip flip) {
	this->flip = flip;
}

void Sprite::rotate(double rotation) {
	this->rotation += rotation;
}

void Sprite::reduceVelocity(double x, double y) {
	velocity.x -= x;
	velocity.y -= y;
}

bool Sprite::collides(Sprite other) {
	double farthestPossible = Vector(size.x / 2, size.y / 2).getLength() + Vector(other.size.x / 2, other.size.y / 2).getLength();
	if ((getCenter() - other.getCenter()).getLength() > farthestPossible) {
		return false;
	}
	printf("Doing SAT\n");
	std::vector<Vector> points = getPoints();
	std::vector<Vector> otherPoints = other.getPoints();
	Vector axi[8];
	for (int i = 0; i < 4; ++i) {
		int next = i + 1;
		if (next > 3) next = 0;
		Vector vec(points[i].x - points[next].x, points[i].y - points[next].y);
		axi[i] = Vector(vec.y, -vec.x);
		printf("Perpendicular vector: %f, %f\n", axi[i].x, axi[i].y);
	}

	for (int i = 0; i < 4; ++i) {
		int next = i + 1;
		if (next > 3) next = 0;
		Vector vec(otherPoints[i].x - otherPoints[next].x, otherPoints[i].y - otherPoints[next].y);
		axi[i + 4] = Vector(vec.y, -vec.x);
	}

	for (int i = 0; i < 8; ++i) {
		double minProj = axi[i].x * points[0].x + axi[i].x * points[0].y + axi[i].y * points[0].x + axi[i].y * points[0].y;
		double maxProj = minProj;
		for (int k = 0; k < 4; ++k) {
			double dot = axi[i].x * points[k].x + axi[i].x * points[k].y + axi[i].y * points[k].x + axi[i].y * points[k].y;
			if (dot < minProj) {
				minProj = dot;
			}
			else if (dot > maxProj) {
				maxProj = dot;
			}
		}
		double otherMinProj = axi[i].x * otherPoints[0].x + axi[i].x * otherPoints[0].y + axi[i].y * otherPoints[0].x + axi[i].y * otherPoints[0].y;
		double otherMaxProj = otherMinProj;
		for (int k = 0; k < 4; ++k) {
			double dot = axi[i].x * otherPoints[k].x + axi[i].x * otherPoints[k].y + axi[i].y * otherPoints[k].x + axi[i].y * otherPoints[k].y;
			if (dot < otherMinProj) {
				otherMinProj = dot;
			}
			else if (dot > otherMaxProj) {
				otherMaxProj = dot;
			}
		}
		if (!((minProj >= otherMinProj && minProj <= otherMaxProj) || (maxProj >= otherMinProj && maxProj <= otherMaxProj))) {
			return false;
		}
	}

	// get normals
	// get normals of other
	// for axis in normals:
	//   get projection
	//   get projection of other
	//   if projections overlap, return false
	// repeat for other normals
	// return true
	printf("Collides\n");
	return true;
}

Vector Sprite::getPosition() {
	return position;
}

Vector Sprite::getCenter() {
	return Vector(position.x + size.x / 2, position.y + size.y / 2);
}

Vector Sprite::getVelocity() {
	return velocity;
}

Vector Sprite::getSize() {
	return size;
}

double Sprite::getRotation() {
	return rotation;
}

SDL_Rect Sprite::getRect() {
	SDL_Rect rect = { (int)position.x, (int)position.y, (int)size.x, (int)size.y };
	return rect;
}

SDL_Texture* Sprite::getTexture() {
	return texture;
}

SDL_RendererFlip Sprite::getFlip() {
	return flip;
}

std::vector<Vector> Sprite::getPoints() {
	double rotationRad = rotation * 3.14159 / 180;

	std::vector<Vector> points;

	double x = position.x;
	double y = position.y;
	double w = size.x;
	double h = size.y;

	Vector p1(x + -w / 2 * cos(rotationRad) - h / 2 * sin(rotationRad) + w / 2,
		y + h / 2 * cos(rotationRad) - w / 2 * sin(rotationRad) + h / 2);

	Vector p2(x + w / 2 * cos(rotationRad) - h / 2 * sin(rotationRad) + w / 2,
		y + h / 2 * cos(rotationRad) + w / 2 * sin(rotationRad) + h / 2);

	Vector p3(x + w / 2 * cos(rotationRad) + h / 2 * sin(rotationRad) + w / 2,
		y + -h / 2 * cos(rotationRad) + w / 2 * sin(rotationRad) + h / 2);

	Vector p4(x + -w / 2 * cos(rotationRad) + h / 2 * sin(rotationRad) + w / 2,
		y + -h / 2 * cos(rotationRad) - w / 2 * sin(rotationRad) + h / 2);

	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);
	points.push_back(p4);

	return points;
}

bool Sprite::SATedge(Vector p1, Vector p2, Vector p3, Sprite other) {
	Vector temp(p2.x - p1.x, p2.y - p1.y);
	Vector vec(-temp.y, temp.x);

	std::vector<Vector> points = other.getPoints();

	bool side = false;
	if ((vec.x * (p3.x - p1.x) + vec.y * (p3.y - p1.y)) >= 0) {
		side = true;
	}

	for (int i = 0; i < 4; ++i) {
		if (side == ((vec.x * (points[i].x - p1.x) + vec.y * (points[i].y - p1.y)) >= 0)) {
			return false;
		}
	}
	return true;
}
