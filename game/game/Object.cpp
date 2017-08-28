#include "Object.h"
#include <vector>


Object::Object()
{
}


Object::~Object()
{
}

void Object::draw()
{
	glColor3f(color.r, color.g, color.b);

	glBegin(shape);

	for (int i = 0; i < tops.size(); i++) {
		points[i].x = tops[i].x*cos(angle) - tops[i].y*sin(angle) + position.x;
		points[i].y = tops[i].y*cos(angle) + tops[i].x*sin(angle) + position.y;
		glVertex2d(points[i].x, points[i].y);
	}

	glEnd();
}

void Object::update()
{

}

Point Object::getPosition()
{
	return position;
}
float Object::getAngle()
{
	return angle;
}
