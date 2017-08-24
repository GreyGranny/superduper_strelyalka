#pragma once
#include "Bullet.h"

class CanBeHit
{
public:
	CanBeHit();
	~CanBeHit();
	virtual void hit(Bullet*) = 0;
};

