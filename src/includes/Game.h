#ifndef GAME_H
#define GAME_H

#include <SDL/SDL.h>

class Game {
	private:
		SDL_Surface* screen;
	public:
		int status;

		Game();
		~Game();
};

#endif