#include <glut.h>
#include <windows.h>
#include <stdlib.h>
#include "Game.h"

int main()
{
	Game* game = new Game(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
	game->run();
}