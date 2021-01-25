#pragma once

#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)//取消scanf返回值的警告
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
//设置光标头文件
#include <conio.h>
#include <Windows.h>
#define WIDE 60
#define HEIGH 20
int lastx;//蛇尾坐标
int lasty;

int score;
int kx;//按键之后坐标变化
int ky;
typedef struct BODY//蛇身体
{
	int  x;
	int  y;
}BODY;
 struct SNAKE //蛇
{
	BODY body[HEIGH * WIDE];
	int size;
}snake;
 //SNAKE snake;
struct FOOD//食物
{
	int  x;
	int  y;
}food;

void initSnake();//初始化蛇
void initFood();//初始化食物
void initUI();//初始化界面空间
void playgame();//启动游戏
void wallUI();
