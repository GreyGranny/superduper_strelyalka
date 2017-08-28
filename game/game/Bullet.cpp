#include "Bullet.h"
#include "Game.h"
#include <vector>

using namespace std;

Bullet::Bullet(Point position, float angle, int speed, int timeLife, int damage)
{
	this->position = position;
	this->angle = 0.0f;
	this->speed = speed;
	this->timeLife = timeLife;
	this->damage = damage;

	tops = vector<Point>(3);
	points = vector<Point>(3);

	tops[0].x = -3;
	tops[0].y = -3;

	tops[1].x = 3;
	tops[1].y = -3;

	tops[2].x = 0;
	tops[2].y = 3;

	color.r = 1;
	color.g = 0;
	color.b = 0;
	shape = GL_TRIANGLE_STRIP;

	timeExist = 0;
	live = true;

	angleRotate = 0.8f;
	dx = speed*cos(angle);
	dy = speed*sin(angle);
}


Bullet::~Bullet()
{
}

void Bullet::update()
{
	if (timeExist >= timeLife) {
		live = false;
	}
	else {
		angle += angleRotate;
		move(dx, dy);
		timeExist += Game::current()->getDelay();
	}
}

void Bullet::die()
{
	live = false;
}
bool Bullet::isLive()
{
	return live;
}

int Bullet::getDamage()
{
	return damage;
}
