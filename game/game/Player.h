#pragma once
#ifndef __PLAYER__
#define __PLAYER__

#include <glut.h>
#include <iostream>
#include "Global.h"
#include "Character.h"

using namespace std;

class Player
{
	Point mouseCoord;
	bool mouseDown;
	bool upPress, downPress, rightPress, leftPress;
public:
	Character* character;

	Player(void);
	~Player(void);

	Point getMouseCoordinates();
	void setMouseCoordinates(float, float);

	bool isUpPress();
	bool isDownPress();
	bool isRightPress();
	bool isLeftPress();

	void setUpPress(bool);
	void setDownPress(bool);
	void setRightPress(bool);
	void setLeftPress(bool);

	bool getMouseDown();
	void setMouseDown(bool);
	void update();
};
#endif;
