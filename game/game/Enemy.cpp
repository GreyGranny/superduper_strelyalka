#include "Enemy.h"
#include "Game.h"

Enemy::Enemy()
{
	radius = 15.0;
	angle = 0.0;
	health = maxHealth = 100;

	position.x = 10.0f;
	position.y = 10.0f;

	tops[0].x = -10;
	tops[0].y = -7;

	tops[1].x = 10;
	tops[1].y = -3;

	tops[2].x = 10;
	tops[2].y = 3;

	tops[3].x = -10;
	tops[3].y = 7;

	speed = 1.0f;
}


Enemy::~Enemy()
{
}

void Enemy::rotate()
{
	Game *game = Game::current();
	Point character_coord = game->player->character->getPosition();
	float catet1 = character_coord.x - position.x;
	float catet2 = character_coord.y - position.y;
	angle = atan(catet2 / catet1);

	if (catet1 < 0)
		angle += 3.14159265359;
}

void Enemy::update()
{
	Game *game = Game::current();
	rotate();
	move(speed*cos(angle), speed*sin(angle));
	//position.x += speed*cos(angle);
	//position.y += speed*sin(angle);
}


void Enemy::draw()
{
	glColor3f(1, 0.29, 0.29);
	glBegin(GL_QUADS);

	for (int i = 0; i < 4; i++)
	{
		points[i].x = tops[i].x*cos(angle) - tops[i].y*sin(angle) + position.x;
		points[i].y = tops[i].y*cos(angle) + tops[i].x*sin(angle) + position.y;

		glVertex2d(points[i].x, points[i].y);
	}

	glEnd();
}

void Enemy::hit(Bullet* bullet)
{
	cout << "hit" << endl;
}