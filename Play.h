#pragma once
#include<iostream>
#include <easyx.h>			// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <graphics.h>
#include <conio.h>
#include"Plant.h"
#include"Map.h"
using namespace std;

void print_begin_surface();

void print_play_ui();

void print_game_ui();

void print_buy_ui();

int control();



Plant buy_plant();