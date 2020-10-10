#include"Map.h"
#include<iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

void Map::change_map(int x, int y, int item) {
	if (item == 0) {
		for (int i = 3 * y; i < 3 * y + 3; i++) {
			map[i][x * 6] = 1;
			map[i][x * 6 + 5] = 1;
			map[i][x * 6 + 1] = 0;
			map[i][x * 6 + 2] = 0;
			map[i][x * 6 + 3] = 0;
			map[i][x * 6 + 4] = 0;
		}
	}
	else if (item == 1) {
		for (int i = 3 * y; i < 3 * y + 3; i++) {
			map[i][x * 6] = 1;
			map[i][x * 6 + 5] = 1;
			//map[i][x * 6 + 1] = 0;
			//map[i][x * 6 + 2] = 0;
			//map[i][x * 6 + 3] = 0;
			//map[i][x * 6 + 4] = 0;
		}
	}
	else if (item == 2) {
		for (int i = 3 * y; i < 3 * y + 3; i++) {
			map[i][x * 6] = 2;
			map[i][x * 6 + 5] = 2;
			//map[i][x * 6 + 1] = 0;
			//map[i][x * 6 + 2] = 0;
			//map[i][x * 6 + 3] = 0;
			//map[i][x * 6 + 4] = 0;
		}
	}
	else if (item == 3) {
		for (int i = 3 * y; i < 3 * y + 3; i++) {
			map[i][x * 6] = 1;
			map[i][x * 6 + 5] = 1;
			//map[i][x * 6 + 1] = 0;
			//map[i][x * 6 + 2] = 0;
			//map[i][x * 6 + 3] = 0;
			//map[i][x * 6 + 4] = 0;
		}
		map[3 * y + 2][x * 6 + 1] = 3;
		map[3 * y + 2][x * 6 + 2] = -1;
		map[3 * y + 2][x * 6 + 3] = -1;
		map[3 * y + 2][x * 6 + 4] = -1;

	}
	else if (item == 11) {
		if (x > 0)map[3 * y][x * 6 - 2] = 0;
		map[3 * y][x * 6 + 1] = 10;
	}
	else if (item == 12) {
		if (x > 0)map[3 * y][x * 6 + 1] = 0;
		map[3 * y][x * 6 + 2] = 10;
	}
	else if (item == 13) {
		if (x > 0)map[3 * y][x * 6 + 2] = 0;
		map[3 * y][x * 6 + 3] = 10;
	}
	else if (item == 14) {
		if (x > 0)map[3 * y][x * 6 + 3] = 0;
		map[3 * y][x * 6 + 4] = 10;
	}
}

Map::Map() {
	map = new int*[9];
	for (int i = 0; i < 9; i++) {
		map[i] = new int [48];
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 48; j++) {
			map[i][j] = 0;
		}
	}
	for (int i = 0; i < 48; i+=6) {
		for (int j = 0; j < 9; j++) {
			map[j][i] = 1;
			map[j][i + 5] = 1;
		}
	}
}

int** Map::get_map() {
	if (Map::cur_map == NULL)
		cur_map = new Map();
	return map;
}

Map* Map::cur_map = NULL;
int **Map::map = NULL;