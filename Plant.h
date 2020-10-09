#pragma once
using namespace std;

class Plant {
private:
	const char* name;
	const int blood;
	const int attack;
	int life;
	int x;
	int y;
	int speed;
public:
	Plant(const char* name_, const int blood_,const int attack_);
	Plant();
	Plant(const Plant* orig);
	int get_attack();
	int get_life();
	int get_speed();
	void dead();
	void place_plant(int x_, int y_);
};