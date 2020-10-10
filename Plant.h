#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include"Bullet.h"
using namespace std;

class Plant {
private:
	char* name;
	int attack;
	int life;
	int x;
	int y;
	int speed;
	int price;
public:
	Plant(char* name_, const int blood_, const int attack_, const int speed_, const int price_);
	Plant();
	Plant(const Plant* orig);
	int get_attack();
	int get_life();
	int get_speed();
	int get_price();
	int get_loc_x();
	int get_loc_y();
	void dead();
	void place_plant(int x_, int y_);
};