#pragma once

class Painter
{
public:
	static const int CellSize = 16;
	void DrawClosedCell(int x, int y); //Ðèñîâàíèå çàêðûòîé êëåòêè
	void DrawPressedCell(int x, int y); //Ðèñîâàíèå íàæàòîé êëåòêè
	void DrawOpenedCell(int x, int y, int MinesAround); //Ðèñîâàíèå îòêðûòîé êëåòêè
	void DrawFlag(int x, int y); //Ðèñîâàíèå ôëàãà
	void DrawMine(int x, int y); //Ðèñîâàíèå ìèíû
private:
	void DrawOpenedCell(int x, int y); //Ðèñîâàíèå îòêðûòêîé êëåòêè.Private, ïîòîìó ÷òî èñïîëüçóåòñÿ òîëüêî âíóòðè ïðîãðàììû
};
