#pragma once

#ifndef __BULLET__
#define __BULLET__

#include <iostream>
#include <math.h>
#include "Global.h"
#include "Movable.h"

class Bullet: public Movable
{
	float radius;
	float angleRotate;

	float dx;
	float dy;

	bool live;
	int timeLife;
	int timeExist;
	int damage;
	
public:
	Bullet(Point, float, int, int, int);
	~Bullet();
	void update();
	void die();
	bool isLive();
	int getDamage();
};

#endif
