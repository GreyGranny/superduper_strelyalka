# include "Character.h"
# include "Game.h"

using namespace std;

Character::Character()
{
	radius = 30.0;
	angle = 0;
	health = 200;
	maxHealth = 200;
	
	centerCoord.x = 400.0f;
	centerCoord.y = 200.0f;

	tops[0].x = -30;
	tops[0].y = -25;

	tops[1].x = 30;
	tops[1].y = -10;

	tops[2].x = 30;
	tops[2].y = 10;

	tops[3].x = -30;
	tops[3].y = +25;
	
	speed = 5;
}

void Character::rotation(Point mouse_coord)
{
	float catet1 = mouse_coord.x - centerCoord.x;
	float catet2 = mouse_coord.y - centerCoord.y;
	angle = atan(catet2/catet1);
	
	if(catet1 < 0)
		angle += 3.14159265359;
}
void Character::moveUp()
{
	float dy = 0, dx = 0;
	dy += speed;

	if (centerCoord.y + radius >= Game::getHeightWindow())
		dy = 0;

	moveCenter(dx, dy);
}

void Character::moveDown()
{
	float dy = 0, dx = 0;
	dy -= speed;

	if (centerCoord.y - radius <= 0)
		dy = 0;

	moveCenter(dx, dy);
}

void Character::moveLeft()
{
	float dy = 0, dx = 0;

	dx -= speed;
	
	if (centerCoord.x - radius <= 0)
		dx = 0;

	moveCenter(dx, dy);
}

void Character::moveRight()
{
	float dy = 0, dx = 0;

	dx += speed;

	if (centerCoord.x + radius >= Game::getWidthWindow())
		dx = 0;

	moveCenter(dx, dy);
}

void Character::draw()
{
	glColor3f(0.35,0.6,0.79);
	glBegin(GL_QUADS);

	for (int i = 0; i < 4; i++)
	{
		points[i].x = tops[i].x*cos(angle) - tops[i].y*sin(angle) + centerCoord.x;
		points[i].y = tops[i].y*cos(angle) + tops[i].x*sin(angle) + centerCoord.y;

		glVertex2d(points[i].x, points[i].y); 
	}

	glEnd();
}

void Character::moveCenter(int x, int y)
{
	centerCoord.x += x;
	centerCoord.y += y;
}






	
	