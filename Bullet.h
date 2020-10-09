#pragma once
class Bullet {
private:
	int speed;
	int attack;
	int x;
	int y;
public:
	int get_speed();
	int get_attack();
	int get_loc_x();
	int get_loc_y();
};