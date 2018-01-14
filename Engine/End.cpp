#include "End.h"

void End::Draw(Graphics & gfx) const
{
	for (int i = this->_posX; i < _posX + this->width; i++)
	{
		for (int j = this->_posY; j < _posY + this->height; j++)
		{
			gfx.PutPixel(i, j, this->c);
		}
	}

}
