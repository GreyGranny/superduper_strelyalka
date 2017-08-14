#pragma once
#ifndef __WEAPON__
#define __WEAPON__
#include <iostream>
#include <ctime>
#include <list>
#include <iterator>
#include "Global.h"
#include "Bullet.h";


class Weapon
{
	int damage;		      // наносимый урон
	int capacityCollar;   // вместимость магазина
	int avalibleBullets;  // кол-во пуль доступных для стрельбы
	int maxOfBullets;     // максимально кол-во патронов
	int countBullets;     // доступное кол-во патронов
	int rateOfFire;     // скорострельность
	long lastShootTime;   // время последнего выстрела
	float bulletSpeed;    // скорость пуль

	list<Bullet> bulletList; // список пуль

public:
	Weapon();
	~Weapon();

	void shoot(Point, float);    // стрельба
	void recharge(); // перезарядка
	void updateBullets();
	void drawBullets();
};

#endif