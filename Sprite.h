#pragma once
#include <SDL.h>
#include <string>

class Sprite {
public:
	Sprite(SDL_Texture* texture, double x = 0, double y = 0);
	Sprite(std::string filePath, double x = 0, double y = 0);

	void moveX(double movement);
	void moveY(double movement);
	void move(double moveX, double moveY);
	void setX(double x);
	void setY(double y);
	void setPosition(double x, double y);
	void setCenterX(double x);
	void setCenterY(double y);
	void setCenter(double x, double y);
	void setVelocity(double _xVelocity, double _yVelocity);
	void setRotation(double rotation);
	void setFlip(SDL_RendererFlip flip);
	void rotate(double rotation);
	void reduceVelocity(double _xVelocity, double _yVelocity);
	void free();
	double getX();
	double getCenterX();
	double getY();
	double getCenterY();
	double getXVelocity();
	double getYVelocity();
	double getRotation();
	int getWidth();
	int getHeight();
	SDL_Rect getRect();
	SDL_Texture* getTexture();
	SDL_RendererFlip getFlip();

protected:
	SDL_Texture* texture = nullptr;
	int width = 0;
	int height = 0;
	double x = 0;
	double y = 0;
	double xVelocity = 0;
	double yVelocity = 0;
	double rotation = 0;
	SDL_RendererFlip flip = SDL_FLIP_NONE;
};

