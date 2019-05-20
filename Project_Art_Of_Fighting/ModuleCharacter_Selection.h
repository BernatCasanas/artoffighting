#ifndef _MODULECHARACTERSELECTION_
#define _MODULECHARACTERSELECTION_

#include "Application.h"
#include "Globals.h"
#include "Animation.h"
#include "Module.h"
#include "ModuleTextures.h"
#include "SDL/include/SDL.h"
#include "RectSprites.h"



class ModuleScreenSelection : public Module {
public:
	ModuleScreenSelection();
	~ModuleScreenSelection();
	bool Init();
	bool CleanUp();
	update_status Update();
	bool Start();
	void move();
	void timer();
	void draw();
	void choose();

	SDL_Rect back;

	RectSprites imageSelection1;
	RectSprites imageSelection2;
	RectSprites characters;
	RectSprites name1;
	RectSprites name2;
	RectSprites not_available;

	SDL_Renderer* background;
	SDL_Texture* graphics;

	Animation selector1;
	Animation selector2;

	bool selected = false;

	int SELECTOR_1 = 1;
	int SELECTOR_2 = 2;

	int X_SELECTOR_1 = ((SCREEN_WIDTH / 2) - 28);
	int Y_SELECTOR_1 = ((SCREEN_HEIGHT / 2) + 47);
	int X_SELECTOR_2 = ((SCREEN_WIDTH / 2) + 28);
	int Y_SELECTOR_2 = ((SCREEN_HEIGHT / 2) + 78);

	int tick1 = 0, tick2 = 0;
	char time_char[10];
	int time_int;
	bool no_zero;
};

#endif // !_MODULECHARACTERSELECTION_
