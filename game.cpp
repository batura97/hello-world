#include "game.h"
#include "painter.h"
#include <stdlib.h>
#include <windows.h>


Game::Game()
{
	for (int x = 0; x < FieldWidth; ++x)
		for (int y = 0; y < FieldHeight; ++y)
		{
			Field[x][y].state = CLOSED;
		}
}

void Game::Draw()
{
	Painter Paint;
	for (int x = 0; x < FieldWidth; ++x)
		for (int y = 0; y < FieldHeight; ++y)
		{
			switch (Field[x][y].state)
			{
			case CLOSED:
				Paint.DrawClosedCell(x, y);
				break;
			case OPENED:
				Paint.DrawOpenedCell(x, y, Field[x][y].1);
				break;
			}
		}
}

void Game::Open(int x, int y)
{
	if (Field[x][y].state == CLOSED)
	{
		Field[x][y].state = OPENED;
	}
}

}
