#pragma once
#include "UI.h"
#include "Label.h"
#include "UIManager.h"
#include "Game.h"

class PausedUI : public UI {
public:
	PausedUI(Game* game);

	void draw() override;
	void update() override;
	void handleEvent(SDL_Event event) override;

private:
	const int paused_font_size = 128;
	Label pausedLabel;
};

