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
	int damage;		      // ��������� ����
	int capacityCollar;   // ����������� ��������
	int avalibleBullets;  // ���-�� ���� ��������� ��� ��������
	int maxOfBullets;     // ����������� ���-�� ��������
	int countBullets;     // ��������� ���-�� ��������
	int rateOfFire;     // ����������������
	long lastShootTime;   // ����� ���������� ��������
	float bulletSpeed;    // �������� ����

	list<Bullet> bulletList; // ������ ����

public:
	Weapon();
	~Weapon();

	void shoot(Point, float);    // ��������
	void recharge(); // �����������
	void updateBullets();
	void drawBullets();
};

#endif