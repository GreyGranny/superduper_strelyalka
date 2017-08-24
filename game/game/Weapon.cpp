#include "Weapon.h"
#include "Game.h"

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
	bulletSpeed = 7;
	bulletLife = 1000;
}

Weapon::~Weapon()
{
}

void Weapon::update()
{
	//if (!bulletList.empty())
	//{
	//	list<Bullet*>::iterator iter = bulletList.begin();
	//	while (iter != bulletList.end()) {
	//		(*iter)->update();
	//		if (!(*iter)->isLive())
	//		{
	//			cout << "die" << endl;
	//			delete (*iter);
	//			iter = bulletList.erase(iter);
	//		} else
	//			iter++;
	//	}
	//}
}

void Weapon::draw()
{
	//if (!bulletList.empty())
	//{
	//	list<Bullet*>::iterator iter = bulletList.begin();
	//	while ( iter != bulletList.end() ) {
	//		(*iter)->draw();
	//		iter++;
	//	}
	//}
	char textAvalibleBullets[6] = "";
	char textCountBullets[6] = "";
	char textMaxBullets[6] = "";
	char separator[2] = "/";

	itoa(avalibleBullets, textAvalibleBullets, 10);
	itoa(countBullets, textCountBullets, 10);
	itoa(maxOfBullets, textMaxBullets, 10);

	glPushMatrix();
	glLoadIdentity();

	glColor3f(0.41, 0.13, 0.48);

	Global::textOut(50, Game::current()->getHeightWindow() - 50, "Avalible bullets");
	Global::textOut(220, Game::current()->getHeightWindow() - 50, textAvalibleBullets);

	Global::textOut(50, Game::current()->getHeightWindow() - 80, "Bullets");
	Global::textOut(150, Game::current()->getHeightWindow() - 80, textCountBullets);
	Global::textOut(190, Game::current()->getHeightWindow() - 80, separator);
	Global::textOut(200, Game::current()->getHeightWindow() - 80, textMaxBullets);

	glPopMatrix();
}

void Weapon::shoot(Point position, float angle)
{
	long now = clock();
	int diff = now - lastShootTime;

	if(diff >= rateOfFire)
	{
		if (avalibleBullets > 0) {
			avalibleBullets--; // ��������� ���-�� ���� ��������� � ��������
			lastShootTime = now; // ����� ���������� ��������
			Bullet* b = new Bullet(position, angle, bulletSpeed, bulletLife, damage);
			Game::current()->bulletManager->push(b);
			//bulletList.push_back(b);
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
		int add = capacityCollar - avalibleBullets;
		if (add > countBullets)
			add = countBullets;
		avalibleBullets += add;
		countBullets -= add; // ��������� ����� ���-�� ����
		// ������ ���� �����������
		cout << "recharge" << endl;
	}
	else {
		// ������ ���� ������� ��������
		cout << "can't recharge" << endl;
	}
}