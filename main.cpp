#include <SDL.h>
#include <stdio.h>
#include "Game.h"

int main(int argc, char* argv[]) {
	Game game = Game("Test", false);
	game.loop();
	return 0;
}