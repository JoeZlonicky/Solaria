#include "Label.h"
#include "AssetLoader.h"

Label::Label(std::string text, std::string fontPath, int fontSize, Uint8 r, Uint8 g, Uint8 b, int x, int y) : Sprite(nullptr, x, y), text(text), fontPath(fontPath), fontSize(fontSize), color({ r, g, b }) {
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

void Label::updateFont() {
	TTF_CloseFont(font);
	font = AssetLoader::loadFont(fontPath, fontSize);
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
	int w, h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	size = Vector(w, h);
}
