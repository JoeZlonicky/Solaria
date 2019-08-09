#include "UI.h"

UI::UI(Game* game) : game(game) {
	uiManager = game->getUIManager();
	display = game->getDisplay();
	player = game->getPlayer();
	map = game->getMap();
}

void UI::handleEvent(SDL_Event e) {
}

void UI::update() {
}

void UI::draw() {
}

bool UI::pausesGame() {
	return true;
}
