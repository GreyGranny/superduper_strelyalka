# include "Character.h"
# include "Game.h"

using namespace std;

Character::Character()
{
	radius = 30.0;
	angle = 0;
	health = 200;
	maxHealth = 200;
	
	position.x = 0.0f;
	position.y = 0.0f;

	tops[0].x = -30;
	tops[0].y = -25;

	tops[1].x = 30;
	tops[1].y = -10;

	tops[2].x = 30;
	tops[2].y = 10;

	tops[3].x = -30;
	tops[3].y = +25;
	
	speed = 5;

	weapon = new Weapon();
}

void Character::rotation(Point mouse_coord)
{
	float catet1 = mouse_coord.x - position.x;
	float catet2 = mouse_coord.y - position.y;
	angle = atan(catet2/catet1);
	
	if(catet1 < 0)
		angle += 3.14159265359;
}

void Character::moveVertical(int sign)
{
	float dy = 0, dx = 0;
	dy = (speed*sign);
	setPosition(dx, dy);
}

void Character::moveHorizontal(int sign)
{
	float dy = 0, dx = 0;
	dx = (speed*sign);
	setPosition(dx, dy);
}

void Character::draw()
{
	glColor3f(0.35,0.6,0.79);
	glBegin(GL_QUADS);

	for (int i = 0; i < 4; i++)
	{
		points[i].x = tops[i].x*cos(angle) - tops[i].y*sin(angle) + position.x;
		points[i].y = tops[i].y*cos(angle) + tops[i].x*sin(angle) + position.y;

		glVertex2d(points[i].x, points[i].y); 
	}

	glEnd();
	weapon->drawBullets();
}

void Character::setPosition(int x, int y)
{
	position.x += x;
	position.y += y;
}

Point Character::getPosition()
{
	return position;
}

float Character::getAngle()
{
	return angle;
}





	
	