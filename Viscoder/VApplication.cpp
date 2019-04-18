#include "VApplication.h"

void VApplication::Init() {
	SDL_Init(SDL_INIT_EVERYTHING);

	render.window = SDL_CreateWindow("Viscoder", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

	SDL_Delay(3000);

}

void VApplication::Shutdown() {
	SDL_Quit();
}

void VApplication::Render() {
	
}
