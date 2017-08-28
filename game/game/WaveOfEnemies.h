#pragma once
class WaveOfEnemies
{
	int oneTimeCount; // ������� ������ ����� ������������ ������������
	int totalCount; // ������� ����� ������ � ���� �����
	int deadCount; // ������� ��� ������
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

