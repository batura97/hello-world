#include "game.h"
#include "painter.h"
#include <stdlib.h>
#include <time.h>
#include <windows.h>

Game::Game() //�����������
{
	for (int x = 0; x < FieldWidth; ++x)
		for (int y = 0; y < FieldHeight; ++y)
		{
			Field[x][y].state = CLOSED;
			Field[x][y].HasMine = false;
		}

	srand(time(0));

	for (int i = 0; i < 10; ++i) //����, � ������� ������������� �����
	{
		int x, y;
		do
		{
			x = rand() % FieldWidth;
			y = rand() % FieldHeight;
		} while (Field[x][y].HasMine);
		Field[x][y].HasMine = true;
	}

	for (int x = 0; x < FieldWidth; ++x) //���� ����������� ����
		for (int y = 0; y < FieldHeight; ++y)
		{
			if (!Field[x][y].HasMine)
			{
				Field[x][y].MinesAround = 0;
				for (int xx = x - 1; xx <= x + 1; ++xx)
					for (int yy = y - 1; yy <= y + 1; ++yy)
					{
						if ((xx == x && yy == y) || xx < 0 || xx >= FieldWidth || yy < 0 || yy >= FieldHeight) //���� ����� �� ������� ����, �� ����������.
							continue;
						if (Field[xx][yy].HasMine)
							++Field[x][y].MinesAround;
					}
			}
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
				if (!Field[x][y].HasMine)
				{
					Paint.DrawOpenedCell(x, y, Field[x][y].MinesAround);
				}
				else
					Paint.DrawMine(x, y);
				break;
			case FLAG:
				Paint.DrawFlag(x, y);
				break;
			}
		}
}

void Game::Open(int x, int y)
{
	if (Field[x][y].state == CLOSED)
	{
		OpenEmptyCells(x, y);
		Field[x][y].state = OPENED;
	}
	if (Field[x][y].HasMine)
	{
		for (int i = 0; i < FieldWidth; ++i)
			for (int j = 0; j < FieldHeight; ++j)
			{
				Field[i][j].state = OPENED;
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
	if (Field[x][y].MinesAround == 0 && !Field[x][y].HasMine)
	{
		for (int i = x - 1; i <= x + 1; ++i)
			for (int j = y - 1; j <= y + 1; ++j)
			{
				if ((i == x && j == y) || i < 0 || i >= FieldWidth || j < 0 || j >= FieldHeight) //���� ����� �� ������� ����, �� ����������.
					continue;
				Field[i][j].state = OPENED;
				Field[x][y].state = OPENED;
			}
	}
}
