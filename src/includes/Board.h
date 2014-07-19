#ifndef BOARD_H
#define BOARD_H
#include <SDL/SDL.h>
class Board
{
	public:
		int camera_x;
		int camera_y;
	void render(SDL_Surface * where);
	void renderTile(SDL_Surface * where,int x,int y);
	Board();
};
#endif