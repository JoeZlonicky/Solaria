#include "Label.h"
#include "AssetLoader.h"

Label::Label(std::string text, std::string fontPath, int fontSize, Uint8 r, Uint8 g, Uint8 b, int x, int y) : text(text), fontPath(fontPath), fontSize(fontSize), color({ r, g, b }), x(x), y(y) {
	updateFont();
	updateTexture();
}

void Label::updateText(std::string text) {
	this->text = text;
	updateTexture();
}

void Label::updateFontSize(int size) {
	fontSize = size;
	updateFont();
}

void Label::updateColor(Uint8 r, Uint8 g, Uint8 b) {
	color = { r, g, b };
	updateTexture();
}

void Label::setX(int x) {
	this->x = x;
}

void Label::setY(int y) {
	this->y = y;
}

void Label::setPosition(int x, int y) {
	setX(x);
	setY(y);
}

SDL_Rect Label::getRect() {
	return { x, y, width, height };
}

SDL_Texture* Label::getTexture() {
	return texture;
}

int Label::getWidth() {
	return width;
}

int Label::getHeight() {
	return height;
}

void Label::free() {
	SDL_DestroyTexture(texture);
	texture = NULL;
	TTF_CloseFont(font);
	font = NULL;
}

void Label::updateFont() {
	TTF_CloseFont(font);
	font = TTF_OpenFont(fontPath.c_str(), fontSize);
	if (font == NULL) {
		printf("Failed to open font from %s. Error: %s\n", fontPath.c_str(), TTF_GetError());
	}
}

void Label::updateTexture() {
	SDL_DestroyTexture(texture);
	SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), color);
	if (surface == NULL) {
		printf("Failed to create texture from %s. Error: %s\n", fontPath.c_str(), TTF_GetError());
	}
	texture = AssetLoader::LoadTexture(surface);
	if (texture == NULL) {
		printf("Failed to create texture from surface. Error: %s\n", SDL_GetError());
	}
	SDL_FreeSurface(surface);
	SDL_QueryTexture(texture, NULL, NULL, &width, &height);
}
