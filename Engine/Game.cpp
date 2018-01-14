/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"


Game::Game( MainWindow& wnd )
	:
	wnd( wnd),
	gfx(wnd),
	rng(rd()),
	xDist(0,770),
	yDist(0,570),
	vDist(-1, 1)
{
	for (int i = 0; i < this->_numPoos; i++)
	{
		poos[i].Init(xDist(rng), yDist(rng), vDist(rng), vDist(rng));
	}
	end.Update(xDist(rng), yDist(rng));

}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}
void Game::UpdateModel()
{

	if( isStarted )
	{
	
		dude.Update(wnd.kbd);
		dude.ClampToScreen();
		for (int i = 0; i < this->_numPoos; i++)
		{
			poos[i].Update();
			poos[i].ProcessConsumption(dude);
		}
	}
	else
	{
		if( wnd.kbd.KeyIsPressed( VK_RETURN ) )
		{
			isStarted = true;
		}
	}
}
void Game::ComposeFrame()
{
	//if( !isStarted )
	//{
	//	this->menu.SetMenuState(0);
	//	this->menu.SetMenuPos(325,211);
	//	this->menu.Draw(gfx);
	//}
	//else
	//{
	//	bool allEaten = true;

	//	for (int i = 0; i < this->_numPoos; i++)
	//	{
	//		allEaten = allEaten & poos[i].IsEaten();
	//	}
	//	if(allEaten)
	//	{
	//		this->menu.SetMenuState(2);
	//		this->menu.SetMenuPos(325, 211);
	//		this->menu.Draw(gfx);
	//	}
	//	dude.Draw(gfx);
	//	end.Draw(gfx);
	//	end.UpdateColor();
	//	for (int i = 0; i < this->_numPoos; i++)
	//	{
	//		if (!poos[i].IsEaten())
	//		{
	//			poos[i].Draw(gfx);
	//		}
	//	}
	//}


	SegmentMeter meter(0, 0,1,10);
	meter.addone();
	meter.Draw(gfx);
}
