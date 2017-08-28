#pragma once
class WaveOfEnemies
{
	int oneTimeCount; // сколько врагов может существовать одновременно
	int totalCount; // сколько всего врагов в этой волне
	int deadCount; // сколько уже умерло
	bool finished;
public:
	WaveOfEnemies();
	~WaveOfEnemies();

	int getTotal();
	int getDeadCount();
	int getOneTimeCount();
	bool isFinished();
	void increaseDeadCount();
};

