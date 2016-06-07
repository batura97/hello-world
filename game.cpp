#include "game.h"
#include "painter.h"
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <iostream>
#include <ctime>

Painter Paint;
Game::Game() //Конструктор
{
	stateGame = PLAY;
	startTime = clock() / 1000;
	for (int x = 0; x < FIELD_WIDTH; ++x)
		for (int y = 0; y < FIELD_HEIGHT; ++y)
		{
			Field[x][y].state = CLOSED;
			Field[x][y].HasMine = false;
		}

	srand(time(0));

	for (int i = 0; i < NUMBER_OF_MINES; ++i) //Цикл, в котором расставляются бомбы
	{
		int x, y;
		do
		{
			x = rand() % FIELD_WIDTH;
			y = rand() % FIELD_HEIGHT;
		} while (Field[x][y].HasMine);
		Field[x][y].HasMine = true;
	}

	for (int x = 0; x < FIELD_WIDTH; ++x) //Цикл расстановки цифр
		for (int y = 0; y < FIELD_HEIGHT; ++y)
		{
			if (!Field[x][y].HasMine)
			{
				Field[x][y].MinesAround = 0;
				for (int xx = x - 1; xx <= x + 1; ++xx)
					for (int yy = y - 1; yy <= y + 1; ++yy)
					{
						if ((xx == x && yy == y) || xx < 0 || xx >= FIELD_WIDTH || yy < 0 || yy >= FIELD_HEIGHT) //Если вышли за границы поля, то продолжить.
							continue;
						if (Field[xx][yy].HasMine)
							Field[x][y].MinesAround++;
					}
			}
		}
}

void Game::Draw()
{
	for (int x = 0; x < FIELD_WIDTH; ++x)
		for (int y = 0; y < FIELD_HEIGHT; ++y)
		{
			switch (Field[x][y].state)
			{
			case CLOSED:
				Paint.DrawClosedCell(x, y);
				break;
			case OPENED:
				if (!Field[x][y].HasMine)
					Paint.DrawOpenedCell(x, y, Field[x][y].MinesAround);
				else
					Paint.DrawMine(x, y);
				break;
			case FLAG:
				Paint.DrawFlag(x, y);
				break;
			}
		}

}

void Game::DrawGameOver(char * text, int x)
{
	int Time = (int)(endTime - startTime);
	Paint.DrawComplete(text, x, points / 100, (points / 10) % 10, points % 10, Time / 100, (Time / 10) % 10, Time & 10);
}

void Game::Open(int x, int y)
{
	Painter Paint;
	int points_ = 0;

	if (Field[x][y].state != FLAG)
	{
		if (Field[x][y].state == CLOSED)
			OpenEmptyCells(x, y);
		if (Field[x][y].HasMine)
		{
			stateGame = GAME_OVER;
			endTime = clock() / 1000;
		}
		for (int i = 0; i < FIELD_WIDTH; i++)
			for (int j = 0; j < FIELD_WIDTH; j++)
				if (Field[i][j].state == OPENED || Field[i][j].state == FLAG)
					points_++;
		points = points_;
		points_ = 0;
		if (points == FIELD_WIDTH * FIELD_HEIGHT)
		{
			endTime = clock() / 1000;
			stateGame = WIN;
		}
	}
}

void Game::Mark(int x, int y)
{
	switch (Field[x][y].state)
	{
	case CLOSED:
		Field[x][y].state = FLAG;
		break;
	case FLAG:
		Field[x][y].state = CLOSED;
		break;
	}
}

void Game::OpenEmptyCells(int x, int y)
{
	Field[x][y].state = OPENED;

	if (Field[x][y].MinesAround == 0 && !Field[x][y].HasMine)
	{
		for (int i = x - 1; i <= x + 1; i++)
			for (int j = y - 1; j <= y + 1; j++)
			{
				if ((i == x && j == y) || i < 0 || i >= FIELD_WIDTH || j < 0 || j >= FIELD_HEIGHT) //Если вышли за границы поля, то продолжить.
					continue;
				Field[i][j].state = OPENED;
				Field[x][y].state = OPENED;
			}
	}

}
