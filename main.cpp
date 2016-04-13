#include <windows.h>
#include <glut.h>  
#include "painter.h"
#include "game.h"
#include <iostream>

Game game;

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	game.Draw();
	glutSwapBuffers();
}

void Mouse(int button, int state, int x, int y)
{
	if (state == GLUT_UP)
	{
		switch (button) {
		case GLUT_LEFT_BUTTON:
			game.Open(x / 16, y / 16);
			break;
		}
		glutPostRedisplay();
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(Game::FieldWidth * Painter::CellSize, Game::FieldHeight * Painter::CellSize);
	glutInitWindowPosition(Game::FieldWidth * Painter::CellSize, Game::FieldHeight * Painter::CellSize);
	glutCreateWindow("Ñàïžð");
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, Game::FieldWidth * Painter::CellSize, Game::FieldHeight * Painter::CellSize, 0, -1.0, 1.0);
	glutDisplayFunc(Display);
	glutMouseFunc(Mouse);
	glutMainLoop();
}
