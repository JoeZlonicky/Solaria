#include <SDL.h>
#include "Sprite.h"
#include "TextureManager.h"


Sprite::Sprite(SDL_Texture* texture, double x, double y) {
	this->texture = texture;
	this->x = x;
	this->y = y;
	SDL_QueryTexture(texture, NULL, NULL, &width, &height);
}

Sprite::Sprite(std::string filePath, double x, double y) : Sprite(TextureManager::Load(filePath), x, y) {
}

void Sprite::moveX(double movement) {
	x += movement;
}

void Sprite::moveY(double movement) {
	y += movement;
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

void Sprite::free() {
	SDL_DestroyTexture(texture);
	texture = nullptr;
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
