#ifndef __CHARACTER__
#define __CHARACTER__

#include <glut.h>
#include <iostream>
#include <math.h>
#include "Global.h"

using namespace std;

class Character
{

	Point points[4];
	Point tops[4];
	Point position;
	
	float radius;
	float angle;
	float speed;
	int health;
	int maxHealth;

public:
	
	Character();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void moveCenter(int, int);
	void draw();
	void rotation(Point);
	Point getPosition();
};

#endif