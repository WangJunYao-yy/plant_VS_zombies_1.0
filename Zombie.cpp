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

Zombie::Zombie(char* name_, int life_, int attack_, int speed_) {
	name = new char;
	strcpy(name, name_);
	life = life_;
	attack = attack_;
	speed = speed_;
}
