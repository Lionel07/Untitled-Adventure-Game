#ifndef STATUS_BAR_H
#define STATUS_BAR_H

#define ICON_HEART 0
#define ICON_HALFHEART 1
#define ICON_EMPTYHEART 2

class StatusBar {
	private:
		SDL_Surface * font;
		SDL_Surface * statusbar_res;
		void renderText(SDL_Surface * where,char * c, int x, int y);
	public:
		void render(SDL_Surface * where);
		void renderIcon(SDL_Surface * where,char icon_no, int x, int y);
		StatusBar(SDL_Surface * fontset);
};

#endif