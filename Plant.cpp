#include"Plant.h"
#include<iostream>

using namespace std;

Plant::Plant(const char* name_, const int blood_, const int attack_) :blood(blood_), attack(attack_), life(blood_) {
	this->name = new char;
	this->name = name_;
	x = -1;
	y = -1;
}

int Plant::get_attack() {
	return this->attack;
}

int Plant::get_life() {
	return this->life;
}

void Plant::dead() {
	this->name = NULL;
}

void Plant::place_plant(int x_, int y_) {
	x = x_;
	y = y_;
}

Plant::Plant(const Plant* orig) :blood(orig->blood), attack(orig->attack), life(orig->blood) {
	this->name = new char;
	this->name = orig->name;
	this->x = orig->x;
	this->y = orig->y;
}

Plant::Plant() :blood(0), attack(0), life(-1) {
	this->name = new char;
	//this->name = name_;
	x = -1;
	y = -1;
}
