#pragma once
#ifndef __GLOBAL__
#define __GLOBAL__
# include <glut.h>
# include <string>

# define M_PI           3.14159265358979323846

using namespace std;

struct Point
{
	float x, y;

	Point(){}

	Point(float _x, float _y)
	{
		x = _x;
		y = _y;
	}
};

struct Color
{
	float r, g, b;
	Color(){}
	Color(float _r, float _g, float _b)
	{
		r = _r;
		g = _g;
		b = _b;
	}
};


class Global
{
public:
	static void textOut(int, int, char*);
};

#endif