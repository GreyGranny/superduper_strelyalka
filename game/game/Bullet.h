#pragma once

#ifndef __BULLET__
#define __BULLET__

#include <iostream>
#include <math.h>
#include "Global.h"

class Bullet
{
	Point points[3];
	Point tops[3];
	Point position;

	float speed;
	float radius;
	float angle;
	bool isLive;

public:
	Bullet(Point, float, int);
	~Bullet();
	void draw();
	void update();
};

#endif
