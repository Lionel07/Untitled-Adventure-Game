#include "includes/Board.h"
#include <SDL/SDL.h>

Board::Board()
{
	
}
void Board::render(SDL_Surface * where)
{
	if(where == NULL)
	{
		return;
	}
	SDL_FillRect(where, NULL, SDL_MapRGB(where->format, 0xA0, 0xA0, 0xA0));

	renderTile(where,1, 0);
	renderTile(where,1, 1);

	renderTile(where,3, 0);
	renderTile(where,3, 1);

	renderTile(where,0, 3);
	renderTile(where,1, 4);
	renderTile(where,2, 4);
	renderTile(where,3, 4);
	renderTile(where,4, 3);


	renderTile(where,10, 4);
	renderTile(where,11, 3);
	renderTile(where,10, 3);
	renderTile(where,11, 4);

}
void Board::renderTile(SDL_Surface * where,int x, int y) //Tile coords
{
	if(where == NULL)
	{
		return;
	}
	SDL_Rect tilerect;
	tilerect.x = (x * 16) + camera_x;
	tilerect.y = (y * 16) + camera_y;
	tilerect.w = 16;
	tilerect.h = 16;
	SDL_FillRect(where, &tilerect, SDL_MapRGB(where->format, 0xE0, 0x0, 0x0));
}