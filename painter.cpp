#include "painter.h"
#include <glut.h>
#include <cmath>
#include <windows.h>


void Painter::DrawClosedCell(int x, int y) //Îòðèñîâêà çàêðûòîé êëåòêè
{
	glColor3f(0.8f, 0.8f, 0.8f); //Âûáîð öâåòà //Ñâåòëî-ñåðûé
	glBegin(GL_QUADS); //Ðèñîâàíèå êâàäðàòà
	glVertex2f(x * CellSize, y * CellSize); //Ïåðâàÿ êîîðäèíàòà
	glVertex2f((x + 1) * CellSize, y * CellSize); //Âòîðàÿ êîîðäèíàòà
	glVertex2f((x + 1) * CellSize, (y + 1) * CellSize); //Òðåòÿÿ êîîðäèíàòà
	glVertex2f(x * CellSize, (y + 1) * CellSize); //×åòâžðòàÿ êîîðäèíàòà
	glEnd();

	glColor3f(1.0f, 1.0f, 1.0f);  
	glBegin(GL_LINES); //Ðèñîâàíèå îêàéìëÿþùåé ëèíèè
	glVertex2f(x * CellSize, y * CellSize);
	glVertex2f((x + 1) * CellSize - 1, y * CellSize);
	glVertex2f(x * CellSize, y * CellSize);
	glVertex2f(x * CellSize, (y + 1) * CellSize - 1);
	glEnd();

	glColor3f(0.2f, 0.2f, 0.2f);
	glBegin(GL_LINES); //Ðèñîâàíèå îêàéìëÿþùåé ëèíèè
	glVertex2f((x + 1) * CellSize - 1, y * CellSize);
	glVertex2f((x + 1) * CellSize - 1, (y + 1) * CellSize - 1);
	glVertex2f(x * CellSize, (y + 1) * CellSize - 1);
	glVertex2f((x + 1) * CellSize - 1, (y + 1) * CellSize - 1);
	glEnd();
}

void Painter::DrawOpenedCell(int x, int y, int MinesAround) //Îòðèñîâêà îòêðûòîé êëåòêè
{
	DrawOpenedCell(x, y);
	if (MinesAround > 0)
	{
		switch (MinesAround)
		{
		case 1:
			glColor3f(0.0f, 1.0f, 0.0f); //Çåëåíûé
			break;
		case 2:
			glColor3f(0.0f, 0.0f, 1.0f); //Ñèíèé
			break;
		case 3:
			glColor3f(1.0f, 0.0f, 0.0f); //Êðàñíûé
			break;
		case 4:
			glColor3f(0.0f, 0.3f, 0.0f); //Òžìíî-çåëåíûé
			break;
		case 5:
			glColor3f(0.3f, 0.0f, 0.0f); //Êîðè÷íåâûé
			break;
		case 6:
			glColor3f(0.0f, 1.0f, 1.0f); //Ãîëóáîé
			break;
		case 7:
			glColor3f(0.1f, 0.1f, 0.1f); //×žðíûé
			break;
		case 8:
			glColor3f(0.9f, 0.0f, 0.0f); //Îðàíæåâûé
			break;
		}

		glRasterPos2f(x * CellSize + 2, (y + 1) * CellSize - 4); //Îòðèñîâêà öèôðû ñ îïðåäåëåííûì öâåòîì
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '0' + MinesAround);
	}
}

void Painter::DrawFlag(int x, int y)
{
	glColor3f(0.8f, 0.8f, 0.8f); //Âûáîð öâåòà //Ñâåòëî-ñåðûé
	glBegin(GL_QUADS); //Ðèñîâàíèå êâàäðàòà
	glVertex2f(x * CellSize, y * CellSize); //Ïåðâàÿ êîîðäèíàòà
	glVertex2f((x + 1) * CellSize, y * CellSize); //Âòîðàÿ êîîðäèíàòà
	glVertex2f((x + 1) * CellSize, (y + 1) * CellSize); //Òðåòÿÿ êîîðäèíàòà
	glVertex2f(x * CellSize, (y + 1) * CellSize); //×åòâžðòàÿ êîîðäèíàòà
	glEnd();

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES); //Ðèñîâàíèå îêàéìëÿþùåé ëèíèè
	glVertex2f(x * CellSize, y * CellSize);
	glVertex2f((x + 1) * CellSize - 1, y * CellSize);
	glVertex2f(x * CellSize, y * CellSize);
	glVertex2f(x * CellSize, (y + 1) * CellSize - 1);
	glEnd();

	glColor3f(0.2f, 0.2f, 0.2f);
	glBegin(GL_LINES); //Ðèñîâàíèå îêàéìëÿþùåé ëèíèè
	glVertex2f((x + 1) * CellSize - 1, y * CellSize);
	glVertex2f((x + 1) * CellSize - 1, (y + 1) * CellSize - 1);
	glVertex2f(x * CellSize, (y + 1) * CellSize - 1);
	glVertex2f((x + 1) * CellSize - 1, (y + 1) * CellSize - 1);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex2f(x * CellSize + CellSize / 2, y * CellSize + 1);
	glVertex2f(x * CellSize + CellSize / 2, (y + 1) * CellSize - 3);
	glVertex2f(x * CellSize + CellSize / 2 - 2.5, (y + 1) * CellSize - 3);
	glVertex2f(x * CellSize + CellSize / 2 + 2.5, (y + 1) * CellSize - 3);
	glEnd();
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	glVertex2f(x * CellSize + CellSize / 2 , y * CellSize + 1);
	glVertex2f(x * CellSize + CellSize / 2 - 3, y * CellSize + 4);
	glVertex2f(x * CellSize + CellSize / 2 , y * CellSize + 7);
	glEnd();
}

void Painter::DrawMine(int x, int y)
{
	DrawOpenedCell(x, y);
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	for (int i = 0; i < 360; ++i)
	{
		glVertex2f(x * CellSize + CellSize / 2 + 5 * cos(2 * 3.1415926 * i / 360) - 1.5,
			y * CellSize + CellSize / 2 + 5 * sin(2 * 3.1415926 * i / 360) - 1);
	}

	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);
	for (int i = 0; i < 360; ++i)
	{
		glVertex2f(x * CellSize + CellSize / 2 + 1.5 * cos(2 * 3.1415926 * i / 360) - 2.5,
			y * CellSize + CellSize / 2 + 1.5 * sin(2 * 3.1415926 * i / 360) - 2.5);
	}

	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	for (int i = 0; i < 360; ++i)
	{
		glVertex2f(x * CellSize + CellSize / 2 + 1 * cos(2 * 3.1415926 * i / 360) - 3,
			y * CellSize + CellSize / 2 + 1 * sin(2 * 3.1415926 * i / 360) - 3);
	}

	glEnd();
}

void Painter::DrawOpenedCell(int x, int y)
{
	glColor3f(0.5f, 0.5f, 0.5f); //Òåìíî-ñåðûé
	glBegin(GL_QUADS);
	glVertex2f(x * CellSize, y * CellSize);
	glVertex2f((x + 1) * CellSize, y * CellSize);
	glVertex2f((x + 1) * CellSize, (y + 1) * CellSize);
	glVertex2f(x * CellSize, (y + 1) * CellSize);
	glEnd();

	glColor3f(0.2f, 0.2f, 0.2f);
	glBegin(GL_LINES); //Ðèñîâàíèå îêàéìëÿþùåé ëèíèè
	glVertex2f((x + 1) * CellSize - 1, y * CellSize);
	glVertex2f((x + 1) * CellSize - 1, (y + 1) * CellSize - 1);
	glVertex2f(x * CellSize, (y + 1) * CellSize - 1);
	glVertex2f((x + 1) * CellSize - 1, (y + 1) * CellSize - 1);
	glEnd();
}
