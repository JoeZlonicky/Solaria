#include <SDL.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Failed to initialize SDL. Error: %s\n", SDL_GetError());
		return 1;
	}
	return 0;
}