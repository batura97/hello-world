#pragma once

class Painter
{
public:
	static const int CELL_SIZE = 16;
	void DrawClosedCell(int x, int y); //Рисование закрытой клетки
	void DrawOpenedCell(int x, int y, int MinesAround); //Рисование открытой клетки
	void DrawFlag(int x, int y); //Рисование флага
	void DrawMine(int x, int y); //Рисование мины
	void DrawComplete(char *text, int x, int y, int z, int u, int i, int j, int k); //Конец игры
private:
	void DrawOpenedCell(int x, int y); //Рисование открыткой клетки.Private, потому что используется только внутри программы
};
