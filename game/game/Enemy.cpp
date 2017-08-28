#include "Enemy.h"
#include "Game.h"
#include <vector>

Enemy::Enemy()
{
	radius = 15.0;
	angle = 0.0;
	health = maxHealth = 100;

	position.x = 1 + rand() % (Game::current()->getWidthWindow() - 1);
	position.y = 1 + rand() % (Game::current()->getHeightWindow() - 1);

	tops = vector<Point>(4);
	points = vector<Point>(4);

	tops[0].x = -10;
	tops[0].y = -7;

	tops[1].x = 10;
	tops[1].y = -3;

	tops[2].x = 10;
	tops[2].y = 3;

	tops[3].x = -10;
	tops[3].y = 7;

	color.r = 1;
	color.g = 0.29;
	color.b = 0.29;
	shape = GL_QUADS;

	speed = 1.0f;
}


Enemy::~Enemy()
{
	Game::current()->increaseDeadEnemies();
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

bool Enemy::isLive()
{
	return live;
}

void Enemy::update()
{
	Game *game = Game::current();
	rotate();
	move(speed*cos(angle), speed*sin(angle));
}

bool Enemy::isHit(Bullet* bullet)
{
	float lengt = sqrt(pow(position.x - bullet->getPosition().x, 2) + pow(position.y - bullet->getPosition().y, 2));
	if (lengt <= radius) {
		cout << "is hit" << endl;
		return true;
	}
	return false;
}
void Enemy::hit(Bullet* bullet)
{
	health -= bullet->getDamage();
	if (health <= 0)
		live = false;
	cout << "hit" << endl;
}
