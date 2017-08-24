#include "Bullet.h"
#include "Game.h"

using namespace std;

Bullet::Bullet(Point position, float angle, int speed, int timeLife, int damage)
{
	this->position = position;
	this->angle = angle;
	this->speed = speed;
	this->timeLife = timeLife;
	this->damage = damage;

	tops[0].x = -5;
	tops[0].y = -5;

	tops[1].x = 5;
	tops[1].y = -5;

	tops[2].x = 0;
	tops[2].y = 5;

	timeExist = 0;
	live = true;

	angleRotate = 0.8f;
	rotation = 0.0f;
	dx = speed*cos(angle);
	dy = speed*sin(angle);
}


Bullet::~Bullet()
{
}

void Bullet::rotate()
{
	
}

void Bullet::update()
{
	if (timeExist >= timeLife) {
		live = false;
	}
	else {
		rotation += angleRotate;
		move(dx, dy);
		//position.x += dx;
		//position.y += dy;
		timeExist += Game::current()->getDelay();
	}
}

void Bullet::draw()
{
	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i < 3; i++)
	{
		points[i].x = tops[i].x*cos(rotation) - tops[i].y*sin(rotation) + position.x;
		points[i].y = tops[i].y*cos(rotation) + tops[i].x*sin(rotation) + position.y;

		glVertex2d(points[i].x, points[i].y);
	}

	glEnd();
}

bool Bullet::isLive()
{
	return live;
}