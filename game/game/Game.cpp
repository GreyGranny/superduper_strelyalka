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

	windowWidth = wWidth;
	windowHeight = wHeight;

	mapWidth = 2 * windowWidth;
	mapHeight = 2 * windowHeight;
	
	playerAreaBLPoint = Point(windowWidth*0.25, windowHeight*0.25);
	playerAreaTRPoint = Point(windowWidth*0.75, windowHeight*0.75);

	delay = 15;
	player = new Player();
	bulletManager = new BulletManager();

	Point position = player->character->getPosition();
	camera = Point(position.x -  windowWidth*0.5, position.y -  windowHeight*0.5);
}

Game::~Game()
{
}

void Game::initGL()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(getWidthWindow(), getHeightWindow());
	glutCreateWindow("Zombie Nah");
	glClearColor(0.0, 0, 0, 0);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, getWidthWindow(), 0, getHeightWindow());

	//glutFullScreen();

	glutKeyboardFunc(eventKeyboard);
	glutKeyboardUpFunc(eventKeyboardUp);

	glutMouseFunc(eventMouseDown);
	glutPassiveMotionFunc(eventMouseMotion);
	glutMotionFunc(eventMouseUpMotion);

	glutDisplayFunc(display);
	glutTimerFunc(delay, timer, 0);
}

void Game::initMap()
{

}

void Game::run()
{
	initGL();
	initMap();

	Enemy *en = new Enemy();
	enemyList.push_back(en);

	glutMainLoop();
}

void Game::exit()
{
	::exit(0);
}

void Game::drawScene()
{
	Point position = player->character->getPosition();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	// меняем позицию камеры, если персонаж выходят за заданную область
	if (position.x > (camera.x + playerAreaTRPoint.x))
		camera.x = position.x - playerAreaTRPoint.x;

	if (position.x < (camera.x + playerAreaBLPoint.x))
		camera.x = position.x - playerAreaBLPoint.x;

	if (position.y > (camera.y + playerAreaTRPoint.y))
		camera.y = position.y - playerAreaTRPoint.y;

	if (position.y < (camera.y + playerAreaBLPoint.y))
		camera.y = position.y - playerAreaBLPoint.y;
	

	// для удобства  - потом удалить
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);

	glVertex2d(playerAreaBLPoint.x, playerAreaBLPoint.y);
	glVertex2d(playerAreaBLPoint.x, playerAreaTRPoint.y);
	glVertex2d(playerAreaBLPoint.x, playerAreaBLPoint.y);
	glVertex2d(playerAreaTRPoint.x, playerAreaBLPoint.y);
	glVertex2d(playerAreaTRPoint.x, playerAreaBLPoint.y);
	glVertex2d(playerAreaTRPoint.x, playerAreaTRPoint.y);
	glVertex2d(playerAreaBLPoint.x, playerAreaTRPoint.y);
	glVertex2d(playerAreaTRPoint.x, playerAreaTRPoint.y);

	glEnd();
	//------//

	glTranslatef(-camera.x, -camera.y, 0.0f);
	glColor3f(1, 0, 0);
	glBegin(GL_QUADS);

	for (int i = 0; i < 10; i++)
	{
		glVertex2d(i * 200, i * 200);
		glVertex2d(i * 200+10, i * 200+10);
		glVertex2d(i * 200+10, i * 200);
		glVertex2d(i * 200, i * 200+10);
	}

	glEnd();


	if (!enemyList.empty())
	{
		list<Enemy*>::iterator iter = enemyList.begin();
		while (iter != enemyList.end()) {
			(*iter)->draw();
			iter++;
		}
	}
	bulletManager->draw();
	player->character->draw();

}

void Game::update()
{
	player->update();

	if (!enemyList.empty())
	{
		list<Enemy*>::iterator iter = enemyList.begin();
		while (iter != enemyList.end()) {
			(*iter)->update();
			iter++;
		}
	}
	bulletManager->update();
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
		case 'w': case 'W': case 246 : game->player->setUpPress(true); break;
		case 'd': case 'D': case 226 : game->player->setRightPress(true); break;
		case 'a': case 'A': case 244 : game->player->setLeftPress(true); break;
		case 's': case 'S': case 251: case 179: game->player->setDownPress(true); break;
		case 'r': case 'R': case 202: case 234: game->player->character->weapon->recharge(); break;
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


Game* Game::current()
{
	return Game::instance;
}

int Game::getHeightWindow()
{
	return current()->windowHeight;
}

int Game::getWidthWindow()
{
	return current()->windowWidth;
}

int Game::getHeightWorld()
{
	return current()->mapHeight;
}
int Game::getWidthWorld()
{
	return current()->mapWidth;
}

int Game::getDelay()
{
	return delay;
}

void Game::setDelay(int d)
{
	delay = d;
}

Point Game::getPlayerAreaBLPoint()
{
	return current()->playerAreaBLPoint;
}

Point Game::getPlayerAreaTRPoint()
{
	return current()->playerAreaTRPoint;
}

Point Game::getCamera()
{
	return current()->camera;
}