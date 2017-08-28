#pragma once
#ifndef __OBJECT__
#define __OBJECT__
#include <iostream>
#include <vector>
#include "Global.h"

using namespace std;

class Object
{
protected:
	Point position;
	vector<Point> points;
	vector<Point> tops;
	Color color;
	float angle;
	int shape;

public:
	Object();
	~Object();
	Point getPosition();
	float getAngle();
	void draw();
	void update();
};

#endif