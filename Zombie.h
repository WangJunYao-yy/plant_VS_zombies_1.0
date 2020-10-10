#pragma once
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
#include<iostream>


class Zombie {
private:
	char* name;
	int life;
	int attack;
	int speed;

public:
	int get_life();
	int get_attack();
	int get_speed();
	Zombie(char* name_, int life_, int attack_, int speed_);
};