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

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{
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
		bord.CheckWinner();
	if (wnd.mouse.LeftIsPressed())
	{
		if (square() == 1)
		{
			a = true;
		}
		if (square() == 2)
		{
			b = true;
		}
		if (square() == 3)
			c = true;
		if (square() == 4)
			d = true;
		if (square() == 5)
			e = true;
		if (square() == 6)
			f = true;
		if (square() == 7)
			g = true;
		if (square() == 8)
			h = true;
		if (square() == 9)
			i = true;
	}

}

void Game::ComposeFrame()
{
	bord.Draw(gfx);
	if (a == true) 
	{
		bord.play( 0, player);
		
	}
	if (b == true)
	{
		bord.play( 1, player);
		
	}
	if (c == true)
	{
		bord.play( 2, player);
		
	}
	if (d == true)
	{
		bord.play(3, player);
		
	}
	if (e == true) {
		bord.play( 4, player);
	
	}
	if (f == true)
	{
		bord.play( 5, player);
		
	}
	if (g == true)
	{
		bord.play(6, player);
		
	}
	if (h == true)
	{
		bord.play( 7, player);
		
	}
	if (i == true)
	{
		bord.play( 8, player);
		
	}
}

int Game::square()
{
	if (wnd.mouse.LeftIsPressed()==true)
	{
		int Mx = wnd.mouse.GetPosX(); int My = wnd.mouse.GetPosY();
		if (Mx > 0 && Mx < 200 && My < 200 && My>0)
			return 1;
		if (Mx > 200 && Mx < 400 && My < 200 && My>0)
			return 2;
		if (Mx > 400 && Mx < 600 && My < 200 && My>0)
			return 3;
		if (Mx > 0 && Mx < 200 && My < 400 && My>200)
			return 4;
		if (Mx > 200 && Mx < 400 && My < 400 && My>200)
			return 5;
		if (Mx > 400 && Mx < 600 && My < 400 && My>200)
			return 6;
		if (Mx > 0 && Mx < 200 && My < 600 && My>400)
			return 7;
		if (Mx > 200 && Mx < 400 && My < 600 && My>400)
			return 8;
		if (Mx > 400 && Mx < 600 && My < 600 && My>400)
			return 9;
	}
}