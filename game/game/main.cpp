#include <glut.h>
#include <windows.h>
#include <stdlib.h>
#include "Game.h"

int main()
{
	Game* game = new Game(GetSystemMetrics(SM_CXSCREEN)*0.75, GetSystemMetrics(SM_CYSCREEN)*0.75);
	game->run();
}