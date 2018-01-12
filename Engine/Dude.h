#pragma once
#include "Graphics.h"
#include "Keyboard.h"

class Dude
{
public:
	void ClampToScreen();
	void Draw(Graphics &gfx)const;
	void Update(const Keyboard &kbd) {
			if (kbd.KeyIsPressed(VK_RIGHT))
			{
				x += speed;
			}
			if (kbd.KeyIsPressed(VK_LEFT))
			{
				x -= speed;
			}
			if (kbd.KeyIsPressed(VK_DOWN))
			{
			y += speed;
			}
			if (kbd.KeyIsPressed(VK_UP))
			{
				y -= speed;
			}
	}

	int GetX()const { return this->x; }
	int GetY()const { return this->y; }
	static int GetWidth() { return width; }
	static int GetHeight() { return height; }
private:
	int x = 400;
	int y = 300;
	static constexpr int speed = 3;
	static constexpr int width = 20;
	static constexpr int height = 20;
};