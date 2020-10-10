#pragma once
#define _CRT_SECURE_NO_WARNINGS

class Bullet {
private:
	int speed;
	int attack;
	int x;
	int y;
	int loc;
public:
	int get_speed();
	int get_attack();
	int get_loc_x();
	int get_loc_y();
	int get_loc();
	void change_loc();
	Bullet(int speed_, int attack_, int x_, int y_);
};