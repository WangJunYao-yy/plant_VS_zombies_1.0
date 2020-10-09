#include"Play.h"
#include<iostream>
#include <graphics.h>
#include<vector>
#include<Windows.h>
#include <conio.h>
#include"Map.h"
#include"Plant.h"

int score = 0;
int sunshine = 225;
bool gameover = 0;
int plant[3][8] = { 0 };

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


int control() {
	print_game_ui();
	vector <Plant> Peashooter;
	//char input;
	//input = _getch();
	while (!gameover) {
		if (GetAsyncKeyState('B') & 0x8000)
		{
			Plant tmp(buy_plant());
			if (tmp.get_life() != -1) Peashooter.push_back(tmp);
			print_game_ui();
		}
		if (GetAsyncKeyState('Q') & 0x8000)
		{
			system("cls");
			return 0;
		}


	}
	return 0;
}

Plant buy_plant() {
	
	print_buy_ui();

	//char input;
	//input = _getch();
	while (true) {
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			Plant tmp;
			return tmp;
		}
		else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			Plant tmp("Peashooter", 100, 20);
			int x = 0;
			int y = 0;
			Map::change_map(x, y, 2);

			print_buy_ui();
			cout << "按“↑”、“↓”、“←”、“→”来控制想要栽种的位置" << endl;
			Sleep(200);
			//while (true) {
			//int i = 0;
			while (!(GetAsyncKeyState(VK_RETURN) & 0x8000) || plant[y][x] != 0) {
				//Sleep(50);
				//i++;
				if (GetAsyncKeyState(VK_UP) & 0x8000) {
					Sleep(100);
					if (y == 0) continue;
					else {
						Map::change_map(x, y, 1);
						y--;
						Map::change_map(x, y, 2);
					}
				}
				else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
					Sleep(100);
					if (y == 2)continue;
					else {
						Map::change_map(x, y, 1);
						y++;
						Map::change_map(x, y, 2);
					}
				}
				else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
					Sleep(100);
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
					Sleep(100);
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

				print_buy_ui();
				cout << "按“↑”、“↓”、“←”、“→”来控制想要栽种的位置" << endl;


			}
			//}
				Map::change_map(x, y, 3);
				tmp.place_plant(x, y);
				plant[y][x] = 1;
			return tmp;
		}
	}
}