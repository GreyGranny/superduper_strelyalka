#ifndef __MOVABLE__
#define __MOVABLE__

#pragma once
#include "Object.h"

class Movable: public Object
{
protected:
	float speed;

public:
	Movable();
	~Movable();
	void move(float, float);
};

#endif