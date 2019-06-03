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
	Vector* points = getPoints();
	//printf("Points: (%f, %f), (%f, %f), (%f, %f), (%f, %f)\n", points[0].x, points[0].y,
		//points[1].x, points[1].y, points[2].x, points[2].y, points[3].x, points[3].y);
	if (SATedge(points[0], points[1], points[2], other)) {
		printf("failed top left edge\n");
		return false;
	}
	if (SATedge(points[0], points[3], points[2], other)) {
		printf("failed top right edge\n");
		return false;
	}
	if (SATedge(points[2], points[1], points[3],  other)) {
		printf("failed bottom right edge\n");
		return false;
	}
	if (SATedge(points[2], points[3], points[1], other)) {
		printf("failed bottom left edge\n");
		return false;
	}
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

Vector* Sprite::getPoints() {
	double rotationRad = rotation * 3.14159 / 180;

	Vector p1(position.x, position.y);
	Vector p2(position.x + size.x, position.y);
	Vector p3(position.x + size.x, position.y + size.y);
	Vector p4(position.x, position.y + size.y);
	/*

	Vector p1(position.x * cos(rotationRad) + position.y * sin(rotationRad),
		-position.x * sin(rotationRad) + position.y * cos(rotationRad));

	Vector p2((position.x + size.x) * cos(rotationRad) + position.y * sin(rotationRad),
		-(position.x + size.x) * sin(rotationRad) + position.y * cos(rotationRad));

	Vector p3((position.x + size.x) * cos(rotationRad) + (position.y + size.y) * sin(rotationRad),
		-(position.x + size.x) * sin(rotationRad) + (position.y + size.y) * cos(rotationRad));

	Vector p4(position.x * cos(rotationRad) + (position.y + size.y) * sin(rotationRad),
		-position.x * sin(rotationRad) + (position.y + size.y) * cos(rotationRad));
		*/

	Vector points[] = { p1, p2, p3, p4 };
	return points;
}

bool Sprite::SATedge(Vector p1, Vector p2, Vector p3, Sprite other) {
	Vector temp(p2.x - p1.x, p2.y - p1.y);
	Vector vec(-temp.y, temp.x);
	bool side = false;

	if ((vec.x * (p3.x - p1.x) + vec.y * (p3.y - p1.y)) >= 0) {
		side = true;
	}

	Vector* points = other.getPoints();
	//printf("Testing Points: (%f, %f), (%f, %f), (%f, %f), (%f, %f)\n", points[0].x, points[0].y,
		//points[1].x, points[1].y, points[2].x, points[2].y, points[3].x, points[3].y);
	for (int i = 0; i < 4; ++i) {
		if (side == ((vec.x * (points[i].x - p1.x) + vec.y * (points[i].y - p1.y)) >= 0)) {
			return false;
		}
	}
	return true;
}
