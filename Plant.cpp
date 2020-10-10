#include"Plant.h"
#include<iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

Plant::Plant(char* name_, const int blood_, const int attack_, const int speed_, const int price_) : attack(attack_), life(blood_), speed(speed_), price(price_) {
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

Plant::Plant(const Plant* orig) : attack(orig->attack), life(orig->life), speed(orig->speed), price(orig->price) {
	this->name = new char;
	this->name = orig->name;
	this->x = orig->x;
	this->y = orig->y;
}

Plant::Plant() : attack(0), life(0), speed(0), price(0) {
	this->name = new char;
	//this->name = name_;
	x = -1;
	y = -1;
}

int Plant::get_price() {
	return price;
}

int Plant::get_speed() {
	return speed;
}

int Plant::get_loc_x() {
	return x;
}

int Plant::get_loc_y() {
	return y;
}
