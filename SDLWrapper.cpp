#include "SDLWrapper.h"


SDLWrapper::SDLWrapper(void) {
	runFlag = true;
	surface = NULL;
}

SDLWrapper::~SDLWrapper(void) {

}

bool SDLWrapper::init() {
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

	if((surface = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
		return false;
	}

	 //Set the window caption
    SDL_WM_SetCaption("Hello World", NULL );

	return true;
}

int SDLWrapper::run() {
	SDL_Event event;

	while(runFlag) {
		while(SDL_PollEvent(&event)) {
			eventHandler(&event);
		}

		render();
		SDL_Delay( 30 );
	}

	return 0;
}

int SDLWrapper::render() {
	return 0;
}

void SDLWrapper::eventHandler(SDL_Event* event) {
	if(event->type == SDL_QUIT) {
		runFlag = false;
	}
}

int SDLWrapper::cleanup() {
	//Quit SDL
    SDL_Quit();
	return 0;
}
