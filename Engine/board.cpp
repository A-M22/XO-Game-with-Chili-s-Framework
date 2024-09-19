#include "board.h"


void board::Draw(Graphics& dd)
{
	for (int i = 0; i < 9; i++)
	{

		if (sqr[i].isplayed)
		{
			checkbox(dd, i);
		}
	}
	//top
	for(int i=0;i<=5;i++)
		for (int j = 0; j < Graphics::ScreenWidth; j++)
		{
			dd.PutPixel(j,i, 255,  100, 60);
		}
	//left
	for (int i = 0; i <= 5; i++)
		for (int j = 0; j < Graphics::ScreenHeight; j++)
		{
			dd.PutPixel(i, j, 255, 100, 60);
		}
	//bottom
	for (int i = Graphics::ScreenHeight-5; i < Graphics::ScreenHeight; i++)
		for (int j = 0; j < Graphics::ScreenWidth; j++)
		{
			dd.PutPixel(j, i, 255, 100, 60);
		}
	//right
	for (int i = Graphics::ScreenWidth-5; i < Graphics::ScreenWidth; i++)
		for (int j = 0; j < Graphics::ScreenHeight; j++)
		{
			dd.PutPixel(i, j, 255, 100, 60);
		}
	Border(dd);
}

void board::CheckWinner()
{
	if (sqr[0].isplayed == true && sqr[1].isplayed == true && sqr[2].isplayed == true)
		if (sqr[0].draw==true && sqr[1].draw == true && sqr[2].draw == true)
			for (int i = 0; i < 9; i++)
			{
				sqr[i].isplayed = 0;
			}
}

void board::square::Ex(Graphics& dd, int X, int Y)
{
	int x = X, y = Y;
	for(int i=0;i<=80;i++)
	{
		dd.PutPixel(x++, y--, 400, 100, 200);
	}
	x = X, y = Y;
	for (int i = 0; i <= 80; i++)
	{
		dd.PutPixel(x--, y++, 400, 100, 200);
	}
	x = X, y = Y;
	for (int i = 0; i <= 80; i++)
	{
		dd.PutPixel(x--, y--, 400, 100, 200);
	}
	x = X, y = Y;
	for (int i = 0; i <= 80; i++)
	{
		dd.PutPixel(x++, y++, 400, 100, 200);
	}

}


void board::square::Circle(Graphics& dd, int x, int y)
{
	int rad = 89;
	const int rad_sq = rad * rad;
	for (int yloop = y - rad; yloop < y + rad; yloop++)
	{
		for (int xloop = x - rad; xloop < x + rad; xloop++)
		{
			const int xdiff = x - xloop;
			const int ydiff = y - yloop;
			if (xdiff * xdiff + ydiff * ydiff < rad_sq)
				dd.PutPixel(xloop, yloop,250,150,50);
		}
	}
}

void board::play(int sq,bool &player)
{
	
	
		if (sqr[sq].isplayed == false)
		{
			if (player == 0)
			{
				player = !player;
				sqr[sq].draw = 0;
				
			}
			else if (player == 1)
			{
				player = !player;
				sqr[sq].draw = 1;
			}
			sqr[sq].isplayed = true;
		}

}

void board::checkbox(Graphics &dd,int i)
{
			if (sqr[i].draw == false)
			{
				if (i == 0)
					sqr[i].Ex(dd, 100, 100);
				else if (i == 1)
					sqr[i].Ex(dd, 300, 100);
				else if (i == 2)
					sqr[i].Ex(dd, 500, 100);
				else if (i == 3)
					sqr[i].Ex(dd, 100, 300);
				else if (i == 4)
					sqr[i].Ex(dd, 300, 300);
				else if (i == 5)
					sqr[i].Ex(dd, 500, 300);
				else if (i == 6)
					sqr[i].Ex(dd, 100, 500);
				else if (i == 7)
					sqr[i].Ex(dd, 300, 500);
				else if (i == 8)
					sqr[i].Ex(dd, 500, 500);
			}
			else
			{
				if (i == 0)
					sqr[i].Circle(dd, 100, 100);
				else if (i == 1)
					sqr[i].Circle(dd, 300, 100);
				else if (i == 2)
					sqr[i].Circle(dd, 500, 100);
				else if (i == 3)
					sqr[i].Circle(dd, 100, 300);
				else if (i == 4)
					sqr[i].Circle(dd, 300, 300);
				else if (i == 5)
					sqr[i].Circle(dd, 500, 300);
				else if (i == 6)
					sqr[i].Circle(dd, 100, 500);
				else if (i == 7)
					sqr[i].Circle(dd, 300, 500);
				else if (i == 8)
					sqr[i].Circle(dd, 500, 500);
			}
		
	
}

void board::Border(Graphics& dd)
{
	for (int i = 200; i <= 205; i++)
		for (int j = 5; j < Graphics::ScreenHeight-5; j++)
		{
			dd.PutPixel(i, j, 255, 166, 60);
		}
	for (int i = 400; i <= 405; i++)
		for (int j = 5; j < Graphics::ScreenHeight-5; j++)
		{
			dd.PutPixel(i, j, 255, 166, 60);
		}
	for (int i = 595; i <= 599; i++)
		for (int j = 5; j < Graphics::ScreenHeight-5; j++)
		{
			dd.PutPixel(i, j, 255, 166, 60);
		}

	for (int i = 200; i <= 205; i++)
		for (int j = 5; j < 600-5; j++)
		{
			dd.PutPixel(j, i, 255, 166, 60);
		}
	for (int i = 400; i <= 405; i++)
		for (int j = 5; j < 600-5; j++)
		{
			dd.PutPixel(j, i, 255, 166, 60);
		}
}

