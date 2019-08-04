#include "PausedUI.h"

PausedUI::PausedUI(Game* game) : UI(game), pausedLabel("Paused", "assets/upheavtt.ttf", paused_font_size) {
	pausedLabel.setCenter(display->getWidth() / 2, display->getHeight() / 2);
}

void PausedUI::draw() {
	display->draw(&pausedLabel);
}

void PausedUI::update() {
}

void PausedUI::handleEvent(SDL_Event event) {
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_TAB) {
		uiManager->removeTopLayer();
	}
}
