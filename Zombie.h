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
	int loc_x;
	int loc_y;
public:
	int get_life();
	int get_attack();
	int get_speed();
	int get_loc_x();
	int get_loc_y();
	bool Is_gameover();
	void change_loc();
	Zombie(char* name_, int life_, int attack_, int speed_, int loc_y_);
};