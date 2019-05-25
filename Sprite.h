#pragma once
#include <SDL.h>
#include <string>

class Sprite {
public:
	Sprite(SDL_Texture* texture, double x = 0, double y = 0);
	Sprite(std::string filePath, double x = 0, double y = 0);

	void moveX(double movement);
	void moveY(double movement);
	void setCenterX(double x);
	void setCenterY(double y);
	void setCenter(double x, double y);
	void free();
	double getX();
	double getCenterX();
	double getY();
	double getCenterY();
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

