#include <SDL/SDL.h>
#include "includes/Game.h"
#include <stdio.h>
Game::Game()
{
	printf("Starting game!\n");
	status = 1;
	if(SDL_Init( SDL_INIT_VIDEO ) != 0 )
	{
		printf("error: SDL couldn't initialise\n");
		exit(1);
	}
	screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
}

void Game::ProcessSDLEvent(SDL_Event* e)
{
    if(e->type == SDL_QUIT) {
        status = 0;
    }
}

void Game::render()
{
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0xFF, 0xFF));
	SDL_Flip(screen);
}

Game::~Game()
{
	printf("Ending game!\n");
	SDL_Quit();
}