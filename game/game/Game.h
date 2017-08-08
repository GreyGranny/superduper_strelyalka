#ifndef __GAME__
#define __GAME__

#include <glut.h>
#include <iostream>
#include "Character.h"
#include "Player.h"

using namespace std;

class Game
{
	static Game* instance;
	int widthWindow, heightWindow;
	int widthWorld, heightWorld;
	int delay;
public:
	Player* player;

	Game(int, int);
	~Game();
	int getDelay();
	void setDelay(int);
	void update();
	void drawScene();
	void initGL();
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
};
#endif
