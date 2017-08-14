#include "Bullet.h"

using namespace std;

Bullet::Bullet(Point start, float a, int sp)
{
	angle = a;
	position = start;

	tops[0].x = -5;
	tops[0].y = -5;

	tops[1].x = 5;
	tops[1].y = -5;

	tops[2].x = 0;
	tops[2].y = 5;
	speed = sp;

}


Bullet::~Bullet()
{
}

void Bullet::update()
{
	position.x += speed*cos(angle);
	position.y += speed*sin(angle);
	
}

void Bullet::draw()
{
	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLE_STRIP);

	for (int i = 0; i < 3; i++)
	{
		points[i].x = tops[i].x*cos(angle) - tops[i].y*sin(angle) + position.x;
		points[i].y = tops[i].y*cos(angle) + tops[i].x*sin(angle) + position.y;

		glVertex2d(points[i].x, points[i].y);
	}

	glEnd();
}