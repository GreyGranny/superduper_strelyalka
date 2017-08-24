#pragma once
#ifndef __ENEMY__
#define __ENEMY__

#include <glut.h>
#include <iostream>
#include <math.h>
#include "Global.h"
#include "Movable.h"
#include "CanBeHit.h"

using namespace std;
class Enemy: public Movable, public CanBeHit
{
	Point points[4];
	Point tops[4];

	float radius;
	int health;
	int maxHealth;

	//Point position;
	//float angle;
	//float speed;

public:

	Enemy();
	~Enemy();

	void update();
	void draw();
	void rotate();
	void hit(Bullet*);
};

#endif