#pragma once
#include <iomanip>
#include <sstream>

#include "UI.h"
#include "Display.h"
#include "Player.h"
#include "Label.h"
#include "Sprite.h"
#include "UIManager.h"
#include "Game.h"
#include "SDL.h"

class SpaceUI : public UI {
public:
	SpaceUI(Game* game);

	void update() override;
	void draw() override;
	void handleEvent(SDL_Event event) override;

	void displayPlanetName(std::string name);
	void hidePlanetName();
	bool pausesGame();

private:
	const int positionFontSize = 48;
	const int positionLeft = 10;
	const int positionXTop = 4;
	const int positionZTop = 36;
	const int planetNameFontSize = 100;
	const int planetNameBottomOffset = 100;
	const int ammoFontSize = 64;
	const int ammoRight = 8;
	const int ammoTop = 75;
	const int healthBarRight = 8;
	const int healthBarTop = 8;
	const double planetDisplayAlphaIncrease = 2;

	Label xPositionLabel;
	Label zPositionLabel;
	Label planetNameLabel;
	Label ammoCounter;
	Sprite healthBar;
	Sprite healthContainer;
	std::stringstream stream;
	bool showPlanetName = false;
	double planetDisplayAlpha = 0;
};
