#pragma once

#ifndef __BULLET__
#define __BULLET__

#include <iostream>
#include <math.h>
#include "Global.h"
#include "Movable.h"

class Bullet: public Movable
{
	Point points[3];
	Point tops[3];

	//Point position;
	//float angle;
	//float speed;

	float radius;
	float angleRotate;
	float rotation;

	float dx;
	float dy;

	bool live;
	int timeLife;
	int timeExist;
	int damage;
	
public:
	Bullet(Point, float, int, int, int);
	~Bullet();
	void draw();
	void update();
	void rotate();
	bool isLive();
};

#endif
