#include <SDL.h>
#include "Sprite.h"
#include "TextureManager.h"


Sprite::Sprite(SDL_Texture* texture, int x, int y) {
	this->texture = texture;
	this->x = x;
	this->y = y;
	SDL_QueryTexture(texture, NULL, NULL, &width, &height);
}

Sprite::Sprite(std::string filePath, int x, int y) : Sprite(TextureManager::Load(filePath), x, y) {
}

void Sprite::moveX(double movement) {
	x += movement;
}

void Sprite::moveY(double movement) {
	y += movement;
}

void Sprite::free() {
	SDL_DestroyTexture(texture);
	texture = nullptr;
}

double Sprite::getX() {
	return x;
}

double Sprite::getY() {
	return y;
}

int Sprite::getWidth() {
	return width;
}

int Sprite::getHeight() {
	return height;
}

SDL_Rect Sprite::getRect() {
	SDL_Rect rect = { x, y, width, height };
	return rect;
}

SDL_Texture* Sprite::getTexture() {
	return texture;
}
