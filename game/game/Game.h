#ifndef __GAME__
#define __GAME__

#include <glut.h>
#include <iostream>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "BulletManager.h"

using namespace std;

class Game
{
	static Game* instance;
	int windowWidth, windowHeight;
	int mapWidth, mapHeight;
	int delay;
	Point playerAreaBLPoint;
	Point playerAreaTRPoint;
	Point camera;

	list<Enemy*> enemyList; //  список врагов

public:
	Player* player;
	BulletManager *bulletManager;

	Game(int, int);
	~Game();
	int getDelay();
	void setDelay(int);
	void update();
	void drawScene();
	void initGL();
	void initMap();
	void run();
	void exit();

	static Game* current();
	static int getHeightWindow();
	static int getWidthWindow();
	static int getHeightWorld();
	static int getWidthWorld();
	static void eventKeyboard(unsigned char, int, int);
	static void eventKeyboardUp(unsigned char, int, int);
	static void eventMouseDown(int, int, int, int);
	static void eventMouseMotion(int, int);
	static void eventMouseUpMotion(int, int);
	static void display();
	static void timer(int);
	static Point getPlayerAreaBLPoint();
	static Point getPlayerAreaTRPoint();
	static Point getCamera();
};
#endif
