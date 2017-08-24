#include "Movable.h"



Movable::Movable()
{
}


Movable::~Movable()
{
}

void Movable::move(float x, float y)
{
	position.x += x;
	position.y += y;
}

float Movable::getAngle()
{
	return angle;
}
