#pragma once
#include "Graphics.h"
#include "Colors.h"
#include <assert.h>

#ifndef END_H
#define END_H
class End {
public:

	void Draw(Graphics &gfx)const;
	void UpdateColor()
	{
		assert(255 % _colorChangeFrequency == 0);//needs to be divisable by 5
		int R = c.GetR();
		int G = c.GetG();
		int B = c.GetB();
		if (isGTR == false)//then we are going to white
		{
			G = G + _colorChangeFrequency;
			B = B + _colorChangeFrequency;
		}
		else//then we are going to red
		{
			G = G - _colorChangeFrequency;
			B = B - _colorChangeFrequency;
		}
		if (R == 255 && G == 255 && B == 255)//we are white
		{
			isGTR = true;
		}
		else if (R == 255 && G == 0&&B==0)
		{
			isGTR = false;
		}
		c.SetR(R);
		c.SetG(G);
		c.SetB(B);
	}
	void Update(const int x,const int y) {
		this->_posX = x;
		this->_posY = y;
	}
private:

	int _posX;
	int _posY;
	int width = 20;
	int height = 20;
	Color c = Colors::Red;
	int _colorChangeFrequency = 15;
	bool isGTR = false; //is going to red



};



#endif