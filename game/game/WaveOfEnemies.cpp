#include "WaveOfEnemies.h"



WaveOfEnemies::WaveOfEnemies()
{
	totalCount = 2;
	oneTimeCount = 2;
	deadCount = 0;
	finished = false;
}


WaveOfEnemies::~WaveOfEnemies()
{
}

int WaveOfEnemies::getTotal()
{
	return totalCount;
}

int WaveOfEnemies::getDeadCount()
{
	return deadCount;
}

int WaveOfEnemies::getOneTimeCount()
{
	return oneTimeCount;
}

bool WaveOfEnemies::isFinished()
{
	return finished;
}

void WaveOfEnemies::increaseDeadCount()
{
	deadCount++;
	if (deadCount >= totalCount)
		finished = true;
}

void WaveOfEnemies::update()
{
	if (enemyList.size() < oneTimeCount)
		if ((deadCount + enemyList.size()) <  totalCount)
			enemyList.push_back(new Enemy());

	if (!enemyList.empty()) {
		list<Enemy*>::iterator iter = enemyList.begin();
		while (iter != enemyList.end()) {
			(*iter)->update();
			iter++;
		}
	}
}

void WaveOfEnemies::draw()
{
	if (!enemyList.empty())
	{
		list<Enemy*>::iterator iter = enemyList.begin();
		while (iter != enemyList.end()) {
			(*iter)->draw();
			iter++;
		}
	}
}
