#pragma once
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class Map {
private:
	static Map* cur_map;
	static int** map;
	Map();
public:

	static void change_map(int x,int y,int item);
	static int** get_map();
};