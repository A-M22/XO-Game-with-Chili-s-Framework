#pragma once
#include "Graphics.h"
#include "MainWindow.h"
class board
{
private:
	class square
	{
	public:
		bool isplayed = false;
		bool draw = false;
		void Ex(Graphics& dd, int x, int y);
		void Circle(Graphics& dd, int x, int y);
	};
	void Border(Graphics& dd);
	square sqr[9];
public:
	void Draw(Graphics& dd);
	void CheckWinner();
	void play( int sq,bool &player);
	void checkbox(Graphics &dd,int i);
};