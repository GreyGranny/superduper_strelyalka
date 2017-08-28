#include "Game.h"
#include "ExposedToBullets.h"

ExposedToBullets::ExposedToBullets()
{
	Game::current()->addExpToBulletObject(this);
}

ExposedToBullets::~ExposedToBullets()
{
	Game::current()->eraseFromLists(this);
}


