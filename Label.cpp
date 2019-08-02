#include "Label.h"
#include "AssetLoader.h"

Label::Label(std::string text, std::string fontPath, int fontSize, Uint8 r, Uint8 g, Uint8 b, int x, int y) : Sprite(nullptr, x, y), text(text), fontPath(fontPath), fontSize(fontSize), color({ r, g, b }) {
	updateFont();
	updateTexture();
}

void Label::setText(std::string text) {
	this->text = text;
	updateTexture();
}

void Label::setFontSize(int size) {
	fontSize = size;
	updateFont();
}

void Label::setColor(Uint8 r, Uint8 g, Uint8 b) {
	color = { r, g, b };
	updateTexture();
}

void Label::updateFont() {
	TTF_CloseFont(font);
	font = AssetLoader::loadFont(fontPath, fontSize);
}

void Label::updateTexture() {
	SDL_DestroyTexture(texture);
	texture = AssetLoader::CreateTexture(text, font, color);
	int w, h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	size = Vector(w, h);
}
