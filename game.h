#pragma once

class Game
{
public:
	Game();
	void Draw();
	enum {FieldWidth = 9, FieldHeight = 9};
	enum State { CLOSED, OPENED, FLAG};
	struct Cell
	{
		State state;
	};
	Cell Field[FieldWidth][FieldHeight];

};
