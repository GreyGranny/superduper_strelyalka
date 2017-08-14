#include "Weapon.h"

using namespace std;

Weapon::Weapon()
{
	maxOfBullets = 200;
	countBullets = 100;
	capacityCollar = 50;
	avalibleBullets = capacityCollar;
	lastShootTime = 0;
	rateOfFire = 200;
	damage = 10;
	bulletSpeed = 5;
}

Weapon::~Weapon()
{
}

void Weapon::updateBullets()
{
	if (!bulletList.empty())
	{
		list<Bullet>::iterator iter = bulletList.begin();
		while (iter != bulletList.end()) {
			iter->update();
			iter++;
		}
	}
}

void Weapon::drawBullets()
{
	if (!bulletList.empty())
	{
		list<Bullet>::iterator iter = bulletList.begin();
		while (iter != bulletList.end()) {
			iter->draw();
			iter++;
		}
	}
}

void Weapon::shoot(Point position, float angle)
{
	long now = clock();
	int diff = now - lastShootTime;

	if(diff >= rateOfFire)
	{
		if (countBullets > 0 && avalibleBullets > 0) {
			cout << "shoot " << endl;
			avalibleBullets--; // ��������� ���-�� ���� ��������� � ��������
			lastShootTime = now; // ����� ���������� ��������
			Bullet *b = new Bullet(position, angle, bulletSpeed);
			bulletList.push_back(*b);
		}
		else {
			// ������ ���� ������� ��������
			cout << "no bullets" << endl;
		}
	}
}

void Weapon::recharge()
{
	if (countBullets > 0)
	{
		if (countBullets > capacityCollar)
		{
			avalibleBullets = capacityCollar; // ���-�� ���� ��������� � �������� = ����������� ��������
			countBullets -= capacityCollar; // ��������� ����� ���-�� ����
		}
		else {
			avalibleBullets = countBullets;
			countBullets = 0;
		}
		// ������ ���� �����������
		cout << "recharge" << endl;
	}
	else {
		// ������ ���� ������� ��������
		cout << "can't recharge" << endl;
	}
}