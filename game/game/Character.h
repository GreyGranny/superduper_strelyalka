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
	int health;
	int maxHealth;
	float radius;

public:
	
	Weapon *weapon;

	Character();
	void moveVertical(int);
	void moveHorizontal(int);
	void draw();
	void rotation(Point);
};

#endif