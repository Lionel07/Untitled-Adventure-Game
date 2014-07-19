#include <SDL/SDL.h>
#include "includes/StatusBar.h"

StatusBar::StatusBar(SDL_Surface * fontset)
{
	font = fontset;
	if(font == NULL)
	{
		return;
	}
	statusbar_res = SDL_LoadBMP("../res/statusbar.bmp");
	if(statusbar_res == NULL)
	{
		return;
	}
}

void StatusBar::render(SDL_Surface * where)
{
	if(where == NULL)
	{
		return;
	}
	SDL_FillRect(where, NULL, SDL_MapRGB(where->format, 0x0, 0x0, 0x0));

	renderText(where,"-Item 1-",8 * 4,8 * 1);
	renderText(where,"-Item 2-",8 * 16,8 * 1);
	renderText(where,"-Map-",8 * 32,8 * 1);
	renderText(where,"-Life-",8 * 48,8 * 1);

	renderIcon(where,ICON_HEART, 8*48, 16);
	renderIcon(where,ICON_HEART, (8*48) + 8, 16);
	renderIcon(where,ICON_HEART, (8*48) + 16, 16);

	renderText(where,"-Magic-",8 * 48,8 * 6);

	renderText(where,"Status",0,0);
}

SDL_Rect * getGridPos(char c, int res, int cols)
{
	unsigned char row,col;
	row = 0;
	col = 0;
	for(unsigned char i = 0; i != c; i++)
	{
		col++;
		if((col % cols) == 0)
		{
			row++;
			col = 0;
		}
	}
	SDL_Rect * builder = (SDL_Rect*)malloc(sizeof(SDL_Rect));
	builder->x = col * res;
	builder->y = row * res;
	builder->w = res;
	builder->h = res;
	return builder;
}

void StatusBar::renderIcon(SDL_Surface * where,char icon_no, int x, int y)
{
	SDL_Rect pos;
	pos.x = x;
	pos.y = y;
	pos.w = 16;
	pos.h = 16;
	SDL_Rect * temp = getGridPos(icon_no,8,16);
	SDL_BlitSurface( statusbar_res, temp, where, &pos);
	free(temp);

}

void StatusBar::renderText(SDL_Surface * where,char * c, int x, int y)
{
	SDL_Rect * rect_buffer[strlen(c)];
	SDL_Rect pos;
	pos.x = x;
	pos.y = y;
	pos.w = 8;
	pos.h = 8;
	for(unsigned int i = 0; i != strlen(c); i++)
	{
		rect_buffer[i] = getGridPos(c[i], 8, 16);
	}
	for(unsigned int i = 0; i != strlen(c); i++)
	{
		SDL_BlitSurface( font, rect_buffer[i], where, &pos);
		pos.x += 8;
	}
	for(unsigned int i = 0; i != strlen(c); i++)
	{
		free(rect_buffer[i]);
	}
}