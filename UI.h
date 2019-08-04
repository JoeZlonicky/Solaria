#pragma once
#include <SDL.h>
#include "Game.h"
#include "Display.h"
#include "UIManager.h"
#include "Player.h"
#include "Map.h"
#include "SDL.h"

class Game;
class UIManager;

class UI {
public:
	UI(Game* game);

	virtual void handleEvent(SDL_Event e);
	virtual void update();
	virtual void draw();

	virtual bool pausesGame();

protected:
	Game* game;
	UIManager* uiManager;
	Display* display;
	Player* player;
	Map* map;
};