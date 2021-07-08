#include <SDL.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#define INCBIN_STYLE INCBIN_STYLE_SNAKE
#include <incbin.h>
INCBIN(Pragmata, "../../res/PragmataProR_0829.ttf");

#define UNUSED(x) (void)(x)

void fail(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

int main(int argc, char **argv) {
	UNUSED(argc);
	UNUSED(argv);

	int window_height = 1280, window_width = 720;
	long unhandled_events = 0;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER) < 0)
		fail("Could not initialize SDL");

	SDL_Window *window =
			SDL_CreateWindow("Zen", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
							 window_height, window_width, SDL_WINDOW_RESIZABLE);
	if (!window)
		fail("Could not initialize window");

	SDL_Surface *window_surface = SDL_GetWindowSurface(window);
	if (!window_surface)
		fail("Could not initialize window");

	SDL_UpdateWindowSurface(window);

	bool quit = false;
	SDL_Event e;

	while (!quit) {
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
				case SDL_QUIT: {
					quit = true;
				}
					break;
				case SDL_WINDOWEVENT: {
					switch (e.window.event) {
						case SDL_WINDOWEVENT_SIZE_CHANGED: {
							SDL_GetWindowSize(window, &window_width, &window_height);
							printf("Resized to %ix%i\n", window_width, window_height);
						}
							break;
					}
				}
					break;
				default:
					++unhandled_events;
			}
		}
	}
}
