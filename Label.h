#pragma once
#include <SDL_ttf.h>
#include <string>
#include "Sprite.h"

class Label{
public:
	Label(std::string text, std::string fontPath, int fontSize, Uint8 r=255, Uint8 g=255, Uint8 b=255, int x=0, int y=0);
	void updateText(std::string text);
	void updateFontSize(int size);
	void updateColor(Uint8 r, Uint8 g, Uint8 b);
	void setX(int x);
	void setY(int y);
	void setPosition(int x, int y);
	SDL_Rect getRect();
	SDL_Texture* getTexture();
	int getWidth();
	int getHeight();
	void free();

private:
	void updateFont();
	void updateTexture();
	std::string text;
	SDL_Color color;
	std::string fontPath;
	int fontSize;
	TTF_Font* font = nullptr;
	SDL_Texture* texture = nullptr;
	int x;
	int y;
	int width;
	int height;
};

