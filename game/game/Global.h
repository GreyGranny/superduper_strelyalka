#pragma once
#ifndef __GLOBAL__
#define __GLOBAL__
# include <glut.h>
# include <string>

using namespace std;

struct Point
{
	float x,y;

	Point(){}

	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
};

class Global
{

};

#endif