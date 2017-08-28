#pragma once
#ifndef __ENEMY__
#define __ENEMY__

#include <glut.h>
#include <iostream>
#include <math.h>
#include "Global.h"
#include "Movable.h"
#include "ExposedToBullets.h"

using namespace std;
class Enemy: public Movable, public ExposedToBullets
{
	int health;
	int maxHealth;
	float radius;

	bool live;

public:

	Enemy();
	~Enemy();

	void update();
	void rotate();
	bool isLive();
	bool isHit(Bullet*);
	void hit(Bullet*);
};

#endif