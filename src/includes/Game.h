#ifndef GAME_H
#define GAME_H

#include <SDL/SDL.h>
#include "Board.h"
#include "StatusBar.h"
class Game {
	private:
		SDL_Surface* screen;
		SDL_Surface* board;
		SDL_Surface* status_overlay;
	public:
		int status;
		Board * current_board;
		StatusBar * current_statusbar;
		uint64_t draw_ticks;
		Game();
		void ProcessSDLEvent(SDL_Event* e);
		void render();
		void renderText(SDL_Surface * where,char * c, int x, int y);
		~Game();
};

#endif