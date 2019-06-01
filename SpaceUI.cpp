#include "SpaceUI.h"

SpaceUI::SpaceUI(Display* display) : xPositionLabel("0", "assets/upheavtt.ttf", positionFontSize), 
		zPositionLabel("0", "assets/upheavtt.ttf", positionFontSize), healthBar("assets/healthBar.png"), 
		healthContainer("assets/healthContainer.png") {
	this->display = display;
	healthBar.setX((double)display->getWidth() - healthBar.getWidth() - healthBarRight);
	healthBar.setY(healthBarTop);
	healthContainer.setX((double)display->getWidth() - healthContainer.getWidth());
	xPositionLabel.setPosition(positionLeft, positionXTop);
	zPositionLabel.setPosition(positionLeft, positionZTop);
}

void SpaceUI::update(Player* player) {
	xPositionLabel.updateText("x: " + std::to_string(player->getCenterX()));
	zPositionLabel.updateText("z: " + std::to_string(player->getCenterY()));
}

void SpaceUI::draw(Display* display) {
	display->draw(&xPositionLabel);
	display->draw(&zPositionLabel);
	display->draw(&healthContainer);
	display->draw(&healthBar);
}
