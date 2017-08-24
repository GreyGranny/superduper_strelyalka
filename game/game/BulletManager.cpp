#include "BulletManager.h"



BulletManager::BulletManager()
{
}


BulletManager::~BulletManager()
{
}

void BulletManager::update()
{
	if (!bulletList.empty())
	{
		list<Bullet*>::iterator iter = bulletList.begin();
		while (iter != bulletList.end()) {
			(*iter)->update();
			if (!(*iter)->isLive())
			{
				cout << "die" << endl;
				delete (*iter);
				iter = bulletList.erase(iter);
			}
			else
				iter++;
		}
	}
}

void BulletManager::draw()
{
	if (!bulletList.empty())
	{
		list<Bullet*>::iterator iter = bulletList.begin();
		while (iter != bulletList.end()) {
			(*iter)->draw();
			iter++;
		}
	}
}

void BulletManager::push(Bullet *bullet)
{
	bulletList.push_back(bullet);
}
