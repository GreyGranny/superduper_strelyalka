# include <glut.h>
# include <stdlib.h>
# include "Game.h"
# include "Character.h"
# include "Player.h"

Game* Game::instance = NULL;

Game::Game(int wWidth, int wHeight)
{
	if(Game::instance)
		delete Game::instance;

	Game::instance = this;

	widthWindow = wWidth;
	heightWindow = wHeight;

	widthWorld = 2 * widthWindow;
	heightWorld = 2 * heightWindow;

	delay = 15;
	player = new Player();
}


Game::~Game()
{
}

void Game::initGL()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(getWidthWindow(), getHeightWindow());
	glutCreateWindow("Zombie");
	glClearColor(0.0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, getWidthWindow(), 0, getHeightWindow());

	glutFullScreen();

	glutKeyboardFunc(eventKeyboard);
	glutKeyboardUpFunc(eventKeyboardUp);

	glutMouseFunc(eventMouseDown);
	glutPassiveMotionFunc(eventMouseMotion);
	glutMotionFunc(eventMouseUpMotion);

	glutDisplayFunc(display);
	glutTimerFunc(delay, timer, 0);

	glutMainLoop();
}

void Game::run()
{
	initGL();
}

void Game::exit()
{
	::exit(0);
}

Game* Game::current()
{
	return Game::instance;
}

int Game::getHeightWindow()
{
	return current()->heightWindow;
}

int Game::getWidthWindow()
{
	return current()->widthWindow;
}

int Game::getHeightWorld()
{
	return current()->heightWorld;
}
int Game::getWidthWorld()
{
	return current()->widthWorld;
}

int Game::getDelay()
{
	return delay;
}

void Game::setDelay(int d)
{
	delay = d;
}

void Game::drawScene()
{
	player->character->draw();
}

void Game::update()
{
	player->update();
}

void Game::timer(int = 0)
{
	Game* game = current();
	game->update();
	game->display();
	glutTimerFunc(game->delay, timer, 0);
}

void Game::display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	current()->drawScene();
	glFlush();
}

//обработка нажатия клавиш
void Game::eventKeyboard(unsigned char key, int a, int b)
{
	Game* game = Game::current();
	switch(key)
	{
		case 'w': case 246 : game->player->setUpPress(true); break;             
		case 'd': case 226 : game->player->setRightPress(true); break;
		case 'a': case 244 : game->player->setLeftPress(true); break;
		case 's': case 251: case 179: game->player->setDownPress(true); break;
		case 27: game->exit(); break;
	}
}

//обработка отжатия клавиш
void Game::eventKeyboardUp(unsigned char key, int a, int b)
{   
	Game* game = Game::current();
	switch(key)
	{
		case 'w': case 246 : game->player->setUpPress(false); break;             
		case 'd': case 226 : game->player->setRightPress(false); break;
		case 'a': case 244 : game->player->setLeftPress(false); break;
		case 's': case 251 :case 179: game->player->setDownPress(false); break;
	}
}

// обработка нажатия клавишей мышы
void Game::eventMouseDown(int button, int state, int x, int y)
{
	Game* game = current();
	game->player->setMouseDown(state == GLUT_DOWN);
}

// обработка перемещения курсора
void Game::eventMouseMotion(int x, int y)
{
	Game* game = current();
	game->player->setMouseCoordinates(x, y);
}

//обработка перемещения курсора при нажатой клавише мышы
void Game::eventMouseUpMotion(int x, int y)
{
	Game* game = current();
	game->player->setMouseCoordinates(x, y);
}
