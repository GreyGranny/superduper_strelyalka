#ifndef __CHARACTER__
#define __CHARACTER__

#include <glut.h>
#include <iostream>
#include <math.h>
#include "Global.h"
#include "Weapon.h"

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
	
	Weapon *weapon;

	Character();
	void moveVertical(int);
	void moveHorizontal(int);
	void draw();
	void rotation(Point);
	void setPosition(int, int);
	Point getPosition();
	float getAngle();
};

#endif