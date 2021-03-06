#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

#include "Sprite.h"

class Label : public Sprite {
public:
	Label(std::string text, std::string fontPath, int fontSize, 
		Uint8 r=255, Uint8 g=255, Uint8 b=255, int x=0, int y=0);

	void setText(std::string text);
	void setFontSize(int size);
	void setColor(Uint8 r, Uint8 g, Uint8 b);

private:
	void updateFont();
	void updateTexture();

	std::string text;
	SDL_Color color;
	std::string fontPath;
	int fontSize;
	TTF_Font* font = nullptr;
};

