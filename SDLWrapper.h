#pragma once

#ifndef _SDLWRAPPER_
#define _SDLWRAPPER_

#include <SDL/SDL.h>

class SDLWrapper {
private:
	bool runFlag;
	SDL_Surface* surface;

public:
	SDLWrapper(void);
	~SDLWrapper(void);

	bool init();
	void eventHandler(SDL_Event* event);
	int run();
	int render();
	int cleanup();
};

#endif

