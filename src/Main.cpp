#include "includes/Game.h"
#include <SDL/SDL.h>

int main( int argc, char* args[])
{
	//Init Game
	Game * g = new Game();
	SDL_Event Event;
	while(g->status != 0)
	{
		while(SDL_PollEvent(&Event)) {
            g->ProcessSDLEvent(&Event);
        }
        g->render();
	}

	delete g;

	return 0;
}