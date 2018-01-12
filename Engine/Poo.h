#pragma once
#include "Dude.h"
#include "Graphics.h"
#include <assert.h>

class Poo
{
public:
	void Init(int x, int y, int vx, int vy);
	void Update();
	void Draw(Graphics &gfx)const;
	void ProcessConsumption(const Dude &dude );
	bool IsEaten() const { return this->isEaten; }


private:
	int x;
	int y;
	int vx;
	int vy;
	static constexpr int width = 24;
	static constexpr int height = 24;
	bool isEaten = false;
	bool initilized = false;
};