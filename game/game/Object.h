#pragma once
#ifndef __OBJECT__
#define __OBJECT__
#include <iostream>
#include "Global.h"

using namespace std;

class Object
{
protected:
	Point position;

public:
	Object();
	~Object();
	Point getPosition();
};

#endif