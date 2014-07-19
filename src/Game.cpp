#include <SDL/SDL.h>
#include "includes/Game.h"
#include <stdio.h>
#include "includes/Board.h"
#include "includes/StatusBar.h"
SDL_Rect boardrect;
SDL_Rect statusrect;

Game::Game()
{
	printf("Starting game!\n");
	status = 1;
	draw_ticks = 0;
	if(SDL_Init( SDL_INIT_VIDEO ) != 0 )
	{
		printf("error: SDL couldn't initialise\n");
		exit(1);
	}
	screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	statusrect.y = 0;
	statusrect.x = 0;
	statusrect.w = 640;
	statusrect.h = 96;
	boardrect.y = 96;
	boardrect.x = 0;
	boardrect.w = 640;
	boardrect.h = 480 - 96;
	status_overlay = SDL_CreateRGBSurface(0,statusrect.w,statusrect.h,32,0,0,0,0);
	board = SDL_CreateRGBSurface(0,boardrect.w,boardrect.h,32,0,0,0,0);
    current_board = new Board();
    current_statusbar = new StatusBar(SDL_LoadBMP("../res/font.bmp"));
}

void Game::ProcessSDLEvent(SDL_Event* e)
{
    if(e->type == SDL_QUIT) {
        status = 0;
    }
}

void Game::render()
{
	if((draw_ticks % 60) == 0)
	{
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0xFF, 0xEE, 0xEE)); //Clear screen every 100 draw ticks
	}
	
	#ifndef DEBUG_NO_DEV_OVERDRAW
	SDL_FillRect(screen, &boardrect, SDL_MapRGB(screen->format, 0, 0xFF, 0xFF));

	SDL_FillRect(screen, &statusrect, SDL_MapRGB(screen->format, 0, 0, 0));
	#endif

	//Do actual updating here
	current_statusbar->render(status_overlay);
	SDL_BlitSurface( status_overlay, NULL, screen, &statusrect);
	current_board->render(board);
	SDL_BlitSurface(board, NULL, screen, &boardrect);
	SDL_Flip(screen);
	SDL_Delay(1);
	draw_ticks++;
}

Game::~Game()
{
	printf("Ending game!\n");
	SDL_Quit();
}