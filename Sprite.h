#pragma once
#include <SDL.h>
#include <string>
#include <vector>
#include "Vector.h"

class Sprite {
public:
	Sprite(SDL_Texture* texture, double x = 0, double y = 0);
	Sprite(std::string filePath, double x = 0, double y = 0);

	void setX(double x);
	void setY(double y);
	void setPosition(double x, double y);
	void setCenterX(double x);
	void setCenterY(double y);
	void setCenter(double x, double y);
	void setRotation(double rotation);
	void setFlip(SDL_RendererFlip flip);
	void rotate(double rotation);
	void reduceVelocity(double x, double y);
	bool collides(Sprite other);

	Vector getPosition();
	Vector getCenter();
	Vector getVelocity();
	Vector getSize();
	double getRotation();
	SDL_Rect getRect();
	SDL_Texture* getTexture();
	SDL_RendererFlip getFlip();

protected:
	std::vector<Vector> getPoints();
	bool SATedge(Vector p1, Vector p2, Vector p3, Sprite other);
	SDL_Texture* texture = nullptr;
	Vector size;
	Vector position;
	Vector velocity;
	Vector acceleration;
	double rotation = 0;
	SDL_RendererFlip flip = SDL_FLIP_NONE;
};

