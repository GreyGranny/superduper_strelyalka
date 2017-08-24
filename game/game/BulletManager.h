#pragma once
#ifndef __BULLETMANAGER__
#define __BULLETMANAGER__

#include <iostream>
#include <math.h>
#include <list>
#include <iterator>
#include <glut.h>
#include "Global.h"
#include "Bullet.h"

class BulletManager
{
	list<Bullet*> bulletList;
public:
	BulletManager();
	~BulletManager();
	void update();
	void draw();
	void push(Bullet*);
};
#endif;

