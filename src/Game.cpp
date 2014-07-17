#include <SDL/SDL.h>
#include "includes/Game.h"
#include <stdio.h>
Game::Game()
{
	printf("Starting game!\n");
	status = 1;
	SDL_Init( SDL_INIT_EVERYTHING );
	screen = SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE );
}

Game::~Game()
{
	printf("Ending game!\n");
	SDL_Quit();
}