#ifndef __GAME__
#define __GAME__

#include <glut.h>
#include <iostream>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "BulletManager.h"
#include "ExposedToBullets.h"
#include "WaveOfEnemies.h"

using namespace std;

class Game
{
	static Game* instance;
	int windowWidth, windowHeight;
	int mapWidth, mapHeight;
	int tileWidth, tileHeight;
	int delay;

	Point playerAreaBLPoint;
	Point playerAreaTRPoint;
	Point camera;
	Point tileParams;


public:
	Player* player;
	BulletManager *bulletManager;
	WaveOfEnemies *currentWave;

	list<ExposedToBullets*> expToBulletsList;// список объеков по которым можно выстрелить
	//list<Enemy*> enemyList; // список врагов
	list<WaveOfEnemies*> waveList; // список волн

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
	void addExpToBulletObject(ExposedToBullets*);
	void eraseFromLists(ExposedToBullets*);
	void setWaves();
	void increaseDeadEnemies();
	Point getTileParams();

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
