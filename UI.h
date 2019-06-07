#pragma once
#include <SDL.h>

#include "Display.h"

class UI {
public:
	UI(Display* display);

	virtual void handleEvent(SDL_Event e);
	virtual void update(Player* player);
	virtual void draw();

protected:
	Display* display;
};

