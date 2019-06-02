#include <SDL.h>
#include "Sprite.h"
#include "AssetLoader.h"


Sprite::Sprite(SDL_Texture* texture, double x, double y) {
	this->texture = texture;
	this->x = x;
	this->y = y;
	SDL_QueryTexture(texture, NULL, NULL, &width, &height);
}

Sprite::Sprite(std::string filePath, double x, double y) : Sprite(AssetLoader::LoadTexture(filePath), x, y) {
}

void Sprite::moveX(double movement) {
	x += movement;
}

void Sprite::moveY(double movement) {
	y += movement;
}

void Sprite::move(double moveX, double moveY){
	x += moveX;
	y += moveY;
}

void Sprite::setX(double x) {
	this->x = x;
}

void Sprite::setY(double y) {
	this->y = y;
}

void Sprite::setPosition(double x, double y) {
	setX(x);
	setY(y);
}

void Sprite::setCenterX(double x) {
	this->x = x - width / 2;
}

void Sprite::setCenterY(double y) {
	this->y = y - height / 2;
}

void Sprite::setCenter(double x, double y) {
	setCenterX(x);
	setCenterY(y);
}

void Sprite::setVelocity(double _xVelocity, double _yVelocity){
	xVelocity = _xVelocity;
	yVelocity = _yVelocity;
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

void Sprite::reduceVelocity(double _xVelocity, double _yVelocity){
	xVelocity -= _xVelocity;
	yVelocity -= _yVelocity;
}

bool Sprite::collides(Sprite other) {
	if (SATedge(x, y, x + width, y, x + width, y + height, other)) {
		return false;
	}
	if (SATedge(x, y, x, y + height, x + width, y + height, other)) {
		return false;
	}
	if (SATedge(x + width, y + height, x + width, y, x, y, other)) {
		return false;
	}
	if (SATedge(x + width, y + height, x, y + height, x, y, other)) {
		return false;
	}
	return true;
}

double Sprite::getX() {
	return x;
}

double Sprite::getCenterX() {
	return x + width / 2;
}

double Sprite::getY() {
	return y;
}

double Sprite::getCenterY() {
	return y + height / 2;
}

double Sprite::getXVelocity()
{
	return xVelocity;
}

double Sprite::getYVelocity()
{
	return yVelocity;
}

double Sprite::getRotation() {
	return rotation;
}

int Sprite::getWidth() {
	return width;
}

int Sprite::getHeight() {
	return height;
}

SDL_Rect Sprite::getRect() {
	SDL_Rect rect = { (int)x, (int)y, width, height };
	return rect;
}

SDL_Texture* Sprite::getTexture() {
	return texture;
}

SDL_RendererFlip Sprite::getFlip() {
	return flip;
}

bool Sprite::SATedge(double x1, double y1, double x2, double y2, double x3, double y3, Sprite other) {
	double tempX = x2 - x1;
	double tempY = y2 - y1;
	double vecX = -tempY;
	double vecY = tempX;
	bool side = false;
	if ((vecX * (x3 - x1) + vecY * (y3 - y1)) >= 0) {
		side = true;
	}

	if (side == ((vecX * (other.x - x1) + vecY * (other.y - y1)) >= 0)) {
		return false;
	}
	if (side == ((vecX * (other.x + other.width - x1) + vecY * (other.y - y1)) >= 0)) {
		return false;
	}
	if (side == ((vecX * (other.x - x1) + vecY * (other.y + other.height - y1)) >= 0)) {
		return false;
	}
	if (side == ((vecX * (other.x + other.width - x1) + vecY * (other.y + other.height - y1)) >= 0)) {
		return false;
	}
	return true;
}
