#include "Character.h"
#include "Game.h"
#include <vector>

using namespace std;

Character::Character()
{
	radius = 30.0;
	angle = 0;
	health = 200;
	maxHealth = 200;
	
	position.x = 0.0f;
	position.y = 0.0f;

	tops = vector<Point>(4);
	points = vector<Point>(4);

	tops[0].x = -30;
	tops[0].y = -25;

	tops[1].x = 30;
	tops[1].y = -10;

	tops[2].x = 30;
	tops[2].y = 10;

	tops[3].x = -30;
	tops[3].y = 25;
	
	speed = 5;

	color.r = 0.35;
	color.g = 0.6;
	color.b = 0.79;
	shape = GL_QUADS;
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
	move(dx, dy);
}

void Character::moveHorizontal(int sign)
{
	float dy = 0, dx = 0;
	dx = (speed*sign);
	move(dx, dy);
}

void Character::draw()
{
	Object::draw();
	weapon->draw();
}






	
	