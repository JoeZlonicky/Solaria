#pragma once
#include "Label.h"
#include "Sprite.h"
#include "Display.h"
#include "Player.h"

class Player;

class SpaceUI {
public:
	SpaceUI(Display* display);

	void update(Player* player);
	void draw(Display* display);

private:
	const int positionFontSize = 32;
	const int positionLeft = 10;
	const int positionXTop = 4;
	const int positionZTop = 28;
	const int healthBarRight = 8;
	const int healthBarTop = 8;
	Display* display;
	Label xPositionLabel;
	Label zPositionLabel;
	Sprite healthBar;
	Sprite healthContainer;
};

