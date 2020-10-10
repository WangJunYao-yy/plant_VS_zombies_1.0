#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <graphics.h>
#include<vector>
#include<Windows.h>
#include <conio.h>
#include<time.h>

#include"Play.h"
#include"Map.h"
#include"Plant.h"
#include"Bullet.h"
#include"Zombie.h"

int score = 0;
int sunshine = 225;
bool gameover = 0;
//有植物：plant[i][j] = 1
//有僵尸：plant[i][j] = 2
//有子弹：plant[i][j] = 3, plant[i][j] = 4, plant[i][j] = 5, plant[i][j] = 6
int plant[3][8] = { 0 };
double start;

vector <Plant> Peashooter;
vector <Bullet> bullet;



void print_begin_surface() {
	initgraph(640, 480);

	// 读取图片至绘图窗口
	loadimage(NULL, _T(".\\graph\\beginning_surface.jpg"), 640, 300, true);
	// 按任意键退出
	_getch();
	closegraph();
}

void print_play_ui() {
	cout << "\033[32m################################################################################################\033[0m" << endl;

	int** map = Map::get_map();
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 48; j++) {
			if (map[i][j] == 0)cout << "  ";
			if (map[i][j] == 1)cout << "\033[32m# \033[0m";
			if (map[i][j] == 2)cout << "\033[31m# \033[0m";
			if (map[i][j] == 3)cout << "豌豆射手";
			if (map[i][j] == 10)cout << "·";
		}
		cout << endl;
	}
	cout << "\033[32m################################################################################################\033[0m" << endl;
	for (int i = 3; i < 6; i++) {
		for (int j = 0; j < 48; j++) {
			if (map[i][j] == 0)cout << "  ";
			if (map[i][j] == 1)cout << "\033[32m# \033[0m";
			if (map[i][j] == 2)cout << "\033[31m# \033[0m";
			if (map[i][j] == 3)cout << "豌豆射手";
			if (map[i][j] == 10)cout << "·";


		}
		cout << endl;
	}
	cout << "\033[32m################################################################################################\033[0m" << endl;
	for (int i = 6; i < 9; i++) {
		for (int j = 0; j < 48; j++) {
			if (map[i][j] == 0)cout << "  ";
			if (map[i][j] == 1)cout << "\033[32m# \033[0m";
			if (map[i][j] == 2)cout << "\033[31m# \033[0m";
			if (map[i][j] == 3)cout << "豌豆射手";
			if (map[i][j] == 10)cout << "·";


		}
		cout << endl;
	}
	cout << "\033[32m################################################################################################\033[0m" << endl;
}

void print_game_ui() {
	system("cls");

	print_play_ui();

	cout << "===================================================================================================" << endl <<
		"[商店]（按“b”进入购买） 阳光总数： " << sunshine << "						| [得分]" << endl <<
		"---------------------------------------------------------------------------------------------------" << endl <<
		"向日葵50 豌豆射手100									| " << score << endl <<
		"===================================================================================================" << endl;
	cout << "按“Q”可以退出游戏" << endl;

}

void print_buy_ui() {
	system("cls");
	print_play_ui();
	cout << "===================================================================================================" << endl <<
		"[商店]（按“ESC”退出购买，按“Enter”确定购买） 阳光总数： "<<sunshine<<"				| [得分]" << endl <<
		"---------------------------------------------------------------------------------------------------" << endl <<
		"\033[31m豌豆射手100\033[0m         									| " << score << endl <<
		"===================================================================================================" << endl;

}


double count_time() {
	double res = clock() - start;
	//start = clock();
	return res;
}

int control() {
	print_game_ui();

	//char input;
	//input = _getch();
	start = clock();
	int i = 0;
	while (!gameover) {
		Sleep(50);
		i++;
		if (GetAsyncKeyState('B') & 0x8000)
		{
			Plant tmp(buy_plant());
			if (tmp.get_life() != -1) Peashooter.push_back(tmp);
			print_game_ui();
		}
		if (GetAsyncKeyState('Q') & 0x8000)
		{
			system("cls");
			cout << "You have quitted the game!" << endl;
			return 0;
		}

		if (i % 20 == 0) {
			sunshine += 25;
		}
		if (i % 6 == 0) {
			for (int i = 0; i < Peashooter.size(); i++) {
				if (Peashooter[i].get_life() == 0) {
					Peashooter.erase(Peashooter.begin() + i, Peashooter.begin() + i + 1);
					continue;
				}
				Bullet tmp(Peashooter[i].get_speed(), Peashooter[i].get_attack(), Peashooter[i].get_loc_x() + 1, Peashooter[i].get_loc_y());
				bullet.push_back(tmp);
			}
		}
		if (i % 2 == 0) {
			for (int i = 0; i < bullet.size(); i++) {
				if (bullet[i].get_loc_x() == 7 && bullet[i].get_loc() == 4) {
					bullet.erase(bullet.begin() + i, bullet.begin() + i + 1);
					continue;
				}
				Map::change_map(bullet[i].get_loc_x(), bullet[i].get_loc_y(), bullet[i].get_loc() + 10);
				bullet[i].change_loc();
			}
		}
		print_game_ui();
	}
	return 0;
}

Plant buy_plant() {

	print_buy_ui();

	//char input;
	//input = _getch();
	int j = 0;
	while (true) {
		Sleep(50);
		j++;

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			Plant tmp;
			return tmp;
		}
		else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			char* tmp_char = new char[100];
			strcpy(tmp_char, "Peashooter");
			Plant tmp(tmp_char, 100, 20, 10, 100);
			int x = 0;
			int y = 0;
			Map::change_map(x, y, 2);

			print_buy_ui();
			cout << "按“↑”、“↓”、“←”、“→”来控制想要栽种的位置" << endl;
			Sleep(200);

			int i = 0;
			while (true) {

				if (!(GetAsyncKeyState(VK_RETURN) & 0x8000) || plant[y][x] == 1) {
					Sleep(100);
					i++;

					if (GetAsyncKeyState(VK_UP) & 0x8000) {
						if (y == 0) continue;
						else {
							Map::change_map(x, y, 1);
							y--;
							Map::change_map(x, y, 2);
						}
					}
					else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
						if (y == 2)continue;
						else {
							Map::change_map(x, y, 1);
							y++;
							Map::change_map(x, y, 2);
						}
					}
					else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
						if (x == 0 && y == 0)continue;
						else if (x == 0 && y > 0) {
							Map::change_map(x, y, 1);
							x = 7;
							y--;
							Map::change_map(x, y, 2);
						}
						else {
							Map::change_map(x, y, 1);
							x--;
							Map::change_map(x, y, 2);
						}
					}
					else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
						if (x == 7 && y == 2)continue;
						else if (x == 7) {
							Map::change_map(x, y, 1);
							x = 0;
							y++;
							Map::change_map(x, y, 2);
						}
						else {
							Map::change_map(x, y, 1);
							x++;
							Map::change_map(x, y, 2);
						}
					}

					if (i % 10 == 0) {
						sunshine += 25;
					}
					if (i % 3 == 0) {
						for (int i = 0; i < Peashooter.size(); i++) {
							if (Peashooter[i].get_life() == 0) {
								Peashooter.erase(Peashooter.begin() + i, Peashooter.begin() + i + 1);
								continue;
							}
							Bullet tmp(Peashooter[i].get_speed(), Peashooter[i].get_attack(), Peashooter[i].get_loc_x()+1, Peashooter[i].get_loc_y());
							bullet.push_back(tmp);
						}
					}
					if (i % 2 == 0) {
						for (int i = 0; i < bullet.size(); i++) {
							if (bullet[i].get_loc_x() == 7 && bullet[i].get_loc() == 4) {
								bullet.erase(bullet.begin() + i, bullet.begin() + i + 1);
								continue;
							}
							Map::change_map(bullet[i].get_loc_x(), bullet[i].get_loc_y(), bullet[i].get_loc() + 10);
							bullet[i].change_loc();
						}
					}

					print_buy_ui();
					cout << "按“↑”、“↓”、“←”、“→”来控制想要栽种的位置" << endl;

				}
				else break;

			}

			Map::change_map(x, y, 3);
			tmp.place_plant(x, y);
			plant[y][x] = 1;
			sunshine -= tmp.get_price();
			return tmp;
		}
		if (j % 20 == 0) {
			sunshine += 25;
		}
		if (j % 6 == 0) {
			for (int i = 0; i < Peashooter.size(); i++) {
				if (Peashooter[i].get_life() == 0) {
					Peashooter.erase(Peashooter.begin() + i, Peashooter.begin() + i + 1);
					continue;
				}
				Bullet tmp(Peashooter[i].get_speed(), Peashooter[i].get_attack(), Peashooter[i].get_loc_x() + 1, Peashooter[i].get_loc_y());
				bullet.push_back(tmp);
			}
		}
		if (j % 2 == 0) {
			for (int i = 0; i < bullet.size(); i++) {
				if (bullet[i].get_loc_x() == 7 && bullet[i].get_loc() == 4) {
					bullet.erase(bullet.begin() + i, bullet.begin() + i + 1);
					continue;
				}
				Map::change_map(bullet[i].get_loc_x(), bullet[i].get_loc_y(), bullet[i].get_loc() + 10);
				bullet[i].change_loc();
			}
		}
		print_buy_ui();
	}
}