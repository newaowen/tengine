#include "SDLWrapper.h"


int main(int argc, char* args[]) {
	SDLWrapper sdl;

	sdl.init();
	sdl.run();

	return 0;
}


/*
int main( int argc, char* args[] ) {

    //The images
    SDL_Surface* hello = NULL;
    SDL_Surface* screen = NULL;

    //Start SDL
    SDL_Init( SDL_INIT_EVERYTHING );


    //Set up screen
    screen = SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE );

    SDL_Event event;
    bool runFlag = true;
    while(runFlag) {
		while(SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT) {
                runFlag = false;
            }
		}

		//render();
		SDL_Delay( 30);
	}



    //Quit SDL
    SDL_Quit();

    return 0;
}
*/
