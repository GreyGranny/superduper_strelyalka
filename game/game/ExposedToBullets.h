#pragma once
#include <list>
#include "Bullet.h"

class ExposedToBullets
{
public:
	ExposedToBullets();
	virtual ~ExposedToBullets();
	virtual bool isLive() = 0;
	virtual bool isHit(Bullet*) = 0;
	virtual void hit(Bullet*) = 0;
};

