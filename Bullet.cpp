#include"Bullet.h"
#define _CRT_SECURE_NO_WARNNINGS

using namespace std;

int Bullet::get_attack() {
	return attack;
}

int Bullet::get_speed() {
	return speed;
}

int Bullet::get_loc_x() {
	return x;
}

int Bullet::get_loc_y() {
	return y;
}

int Bullet::get_loc() {
	return this->loc;
}

Bullet::Bullet(int speed_, int attack_, int x_, int y_) {
	speed = speed_;
	attack = attack_;
	x = x_;
	y = y_;
	loc = 0;
}

void Bullet::change_loc() {
	if (loc <= 4) {
		loc++;
	}
	else {
		x++;
		loc = 1;
	}
}