#include <SDL.h>
#include "Sprite.h"
#include "AssetLoader.h"


// Create a sprite with a texture
Sprite::Sprite(SDL_Texture* texture, double x, double y) {
	this->texture = texture;
	position = Vector(x, y);
	int w, h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	size = Vector(w, h);
}

// Create a sprite with a filepath of an image
Sprite::Sprite(std::string filePath, double x, double y) : Sprite(AssetLoader::LoadTexture(filePath), x, y) {
}

// Rotate the image and bounding box
void Sprite::rotate(double rotation) {
	this->rotation += rotation;
}

// Decrease velocity
void Sprite::reduceVelocity(double x, double y) {
	velocity.x -= x;
	velocity.y -= y;
}

// Check whether two sprites collide
bool Sprite::collides(Sprite other) {
	double farthestPossible = Vector(size.x / 2, size.y / 2).getLength() + Vector(other.size.x / 2, other.size.y / 2).getLength();
	if ((getCenter() - other.getCenter()).getLength() > farthestPossible) {
		return false;
	}

	std::vector<Vector> points = getBoundingPoints();
	std::vector<Vector> otherPoints = other.getBoundingPoints();
	Vector axi[8];
	for (int i = 0; i < 4; ++i) {
		int next = i + 1;
		if (next > 3) next = 0;
		Vector vec(points[i].x - points[next].x, points[i].y - points[next].y);
		axi[i] = Vector(vec.y, -vec.x).getNormalized();
	}

	for (int i = 0; i < 4; ++i) {
		int next = i + 1;
		if (next > 3) next = 0;
		Vector vec(otherPoints[i].x - otherPoints[next].x, otherPoints[i].y - otherPoints[next].y);
		axi[i + 4] = Vector(vec.y, -vec.x).getNormalized();
	}

	for (int i = 0; i < 8; ++i) {
		if (isSeperatingAxis(axi[i], points, otherPoints)) {
			return false;
		}
	}
	return true;
}

// Get the points of the bounding box
std::vector<Vector> Sprite::getBoundingPoints() {
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

// Determine whether an axis seperates two sets of points
bool Sprite::isSeperatingAxis(Vector axis, std::vector<Vector> points, std::vector<Vector> otherPoints) {
	double minProj = axis.x * points[0].x + axis.y * points[0].y;
	double maxProj = minProj;
	for (int k = 0; k < 4; ++k) {
		double dot = axis.x * points[k].x + axis.y * points[k].y;
		if (dot < minProj) {
			minProj = dot;
		}
		if (dot > maxProj) {
			maxProj = dot;
		}
	}
	double otherMinProj = axis.x * otherPoints[0].x + axis.y * otherPoints[0].y;
	double otherMaxProj = otherMinProj;
	for (int k = 0; k < 4; ++k) {
		double dot = axis.x * otherPoints[k].x + axis.y * otherPoints[k].y;
		if (dot < otherMinProj) {
			otherMinProj = dot;
		}
		if (dot > otherMaxProj) {
			otherMaxProj = dot;
		}
	}
	if (minProj > otherMaxProj || maxProj < otherMinProj) {
		return true;
	}
	return false;
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

void Sprite::setAlpha(Uint8 a) {
	alpha = a;
	SDL_SetTextureAlphaMod(texture, a);
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

Uint8 Sprite::getAlpha() {
	return alpha;
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
