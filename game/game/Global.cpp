#include "Global.h"

void Global::textOut(int x, int y, char *string)
{
	char *c;
	glRasterPos2f(x, y);

	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
}
