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
