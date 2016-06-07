#include <windows.h>
#include <GL/freeglut.h>
#include "painter.h"
#include "game.h"
#include <iostream>

Game game;

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	if (game.stateGame == 0)
		game.Draw();
	else if (game.stateGame == 1)
		game.DrawGameOver("Game Over!", 15);
	else
		game.DrawGameOver("Win!", -5);
	std::cout << game.points << " ";
	glutSwapBuffers();
}

void Mouse(int button, int state, int x, int y)
{
	if (state == GLUT_UP)
	{
		switch (button) {
		case GLUT_LEFT_BUTTON:
			game.Open(x / Game::FIELD_WIDTH, y / Game::FIELD_HEIGHT);
			break;
		case GLUT_RIGHT_BUTTON:
			game.Mark(x / Game::FIELD_WIDTH, y / Game::FIELD_HEIGHT);
			break;
		}
		glutPostRedisplay();
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(Game::FIELD_WIDTH * Painter::CELL_SIZE, Game::FIELD_HEIGHT * Painter::CELL_SIZE);
	glutInitWindowPosition(Game::FIELD_WIDTH * Painter::CELL_SIZE / 2, Game::FIELD_HEIGHT * Painter::CELL_SIZE / 2);
	glutCreateWindow("Сапёр");
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, Game::FIELD_WIDTH * Painter::CELL_SIZE, Game::FIELD_HEIGHT * Painter::CELL_SIZE, 0, -1.0, 1.0);
	glutDisplayFunc(Display);
	glutMouseFunc(Mouse);
	glutMainLoop();
}
