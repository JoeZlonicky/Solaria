#include "Label.h"
#include "AssetLoader.h"

// Create a label
Label::Label(std::string text, std::string fontPath, int fontSize, Uint8 r, Uint8 g, Uint8 b, int x, int y) : Sprite(nullptr, x, y), text(text), fontPath(fontPath), fontSize(fontSize), color({ r, g, b }) {
	updateFont();
	updateTexture();
}

// Set text and update texture
void Label::setText(std::string text) {
	this->text = text;
	updateTexture();
}

// Set font size and update texture
void Label::setFontSize(int size) {
	fontSize = size;
	updateFont();
}

// Set the color of text and update texture
void Label::setColor(Uint8 r, Uint8 g, Uint8 b) {
	color = { r, g, b };
	updateTexture();
}

// Load a new font
void Label::updateFont() {
	font = AssetLoader::loadFont(fontPath, fontSize);
}

// Destroy current texture and create a new one
void Label::updateTexture() {
	SDL_DestroyTexture(texture);
	texture = AssetLoader::CreateTexture(text, font, color);
	int w, h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	size = Vector(w, h);
}
