#pragma once
#ifndef MENU_H
#define MENU_H
#include "Graphics.h"



class Menu {
public:
	void Draw(Graphics &gfx)const;
	void SetMenuPos(int x, int y) { this->x = x; this->y = y; }
	void SetMenuState(int x) {//0title,1playing,2end
		this->_menuState = x;
	}
private:
	int x;
	int y;
	int _menuState = 0;//0title,1playing,2end
	void DrawGameOver(Graphics &gfx)const;
	void DrawTitleScreen(Graphics &gfx)const;
};

#endif