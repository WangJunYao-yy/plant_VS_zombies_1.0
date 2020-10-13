#define _CRT_SECURE_NO_WARNINGS

#include"Zombie.h"
#include<iostream>
using namespace std;

int Zombie::get_life() {
	return life;
}

int Zombie::get_attack() {
	return attack;
}

int Zombie::get_speed() {
	return speed;
}

Zombie::Zombie(char* name_, int life_, int attack_, int speed_,int loc_y_) {
	name = new char;
	strcpy(name, name_);
	life = life_;
	attack = attack_;
	speed = speed_;
	loc_y = loc_y_;
	loc_x = 8;
}

bool Zombie::Is_gameover() {
	if (this->loc_x == -1)return true;
	else return false;
}

int Zombie::get_loc_x() {
	return this->loc_x;
}

int Zombie::get_loc_y() {
	return this->loc_y;
}

void Zombie::change_loc() {
	this->loc_x--;
}