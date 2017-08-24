#pragma once
#ifndef __GLOBAL__
#define __GLOBAL__
# include <glut.h>
# include <string>

# define M_PI           3.14159265358979323846

using namespace std;

struct Point
{
	float x,y;

	Point(){}

	Point(float _x, float _y)
	{
		x = _x;
		y = _y;
	}
};

class Global
{
public:
	static void textOut(int, int, char*);
};

#endif