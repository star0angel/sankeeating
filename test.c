#include "snakeeating.h"


void setconsolenoflash()
{
	CONSOLE_CURSOR_INFO cci;
	//CONSOLE_CURSOR_INFO cci;   
	cci.bVisible = FALSE;
	cci.dwSize = sizeof(cci);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cci);
}
//#include "snakeeating.cpp"
void main()
{

	score = 0;
	//隐藏光标  不闪烁

	setconsolenoflash();
	srand((size_t)(time(NULL)));//置随机数种子
	initSnake();
	initFood();
	wallUI();
	initUI('d');
	playgame();
	//system("pause");
	//system("pause");
	//printf("%d %d\n", food.x, food.y);
	//printf("%d %d", snake.body[0].x, snake.body[0].y);
	//setxy(food.x, food.y);
	//return 0;
}