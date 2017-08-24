#ifndef __CHARACTER__
#define __CHARACTER__

#include <glut.h>
#include <iostream>
#include <math.h>
#include "Movable.h"
#include "Global.h"
#include "Weapon.h"

using namespace std;

class Character: public Movable
{
	Point points[4];
	Point tops[4];

	int health;
	int maxHealth;
	float radius;

	//Point position
	//float angle;
	//float speed;

public:
	
	Weapon *weapon;

	Character();
	void moveVertical(int);
	void moveHorizontal(int);
	void draw();
	void rotation(Point);
	//float getAngle();
	//void setPosition(int, int);
};

#endif