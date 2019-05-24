#pragma once
#include <SDL.h>
#include <string>

class Sprite {
public:
	Sprite(SDL_Texture* texture, int x = 0, int y = 0);
	Sprite(std::string filePath, int x = 0, int y = 0);

	void moveX(double movement);
	void moveY(double movement);
	double getX();
	double getY();
	int getWidth();
	int getHeight();
	SDL_Rect getRect();
	SDL_Texture* getTexture();

private:
	SDL_Texture* texture = nullptr;
	int width = 0;
	int height = 0;
	double x = 0;
	double y = 0;
};

