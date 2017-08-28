#pragma once
#ifndef __WAVEOFENEMIES__
#define __WAVEOFENEMIES__
#include "Enemy.h"
class WaveOfEnemies
{
	int oneTimeCount; // сколько врагов может существовать одновременно
	int totalCount; // сколько всего врагов в этой волне
	int deadCount; // сколько уже умерло
	bool finished;

public:
	list<Enemy*> enemyList; // список врагов

	WaveOfEnemies();
	~WaveOfEnemies();

	int getTotal();
	int getDeadCount();
	int getOneTimeCount();
	bool isFinished();
	void increaseDeadCount();
	void update();
	void draw();
};

#endif;