#pragma once
#ifndef __WAVEOFENEMIES__
#define __WAVEOFENEMIES__
#include "Enemy.h"
class WaveOfEnemies
{
	int oneTimeCount; // ������� ������ ����� ������������ ������������
	int totalCount; // ������� ����� ������ � ���� �����
	int deadCount; // ������� ��� ������
	bool finished;

public:
	list<Enemy*> enemyList; // ������ ������

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