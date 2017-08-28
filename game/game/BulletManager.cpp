#include "BulletManager.h"  
#include "Game.h"

using namespace std;

BulletManager::BulletManager()
{
}


BulletManager::~BulletManager()
{
}

void BulletManager::update()
{
	Game *game = Game::current();
	if (!bulletList.empty()) {
		list<Bullet*>::iterator iter = bulletList.begin();
		while (iter != bulletList.end()) {
			(*iter)->update();

			if (!game->expToBulletsList.empty()) {
				list<ExposedToBullets*>::iterator exp_iter = game->expToBulletsList.begin();
				while (exp_iter != game->expToBulletsList.end()) {
					if ((*exp_iter)->isHit((*iter))) {
						(*exp_iter)->hit((*iter));
						(*iter)->die();
					}

					if (!(*exp_iter)->isLive()) {
						cout << "enemy die" << endl;
						delete (*exp_iter);
						exp_iter = game->expToBulletsList.erase(exp_iter);
					}
					else
						exp_iter++;
				}
			}
			
			
			if (!(*iter)->isLive()) {
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
	if (!bulletList.empty()) {
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
