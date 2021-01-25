#include "snakeeating.h"
//SNAKE snake;
//FOOD food;
void initSnake()
{
	snake.size = 2;
	snake.body[0].x = WIDE / 2;//蛇头初始化
	snake.body[0].y = HEIGH / 2;
	snake.body[1].x = WIDE / 2-1;//蛇身初始化
	snake.body[1].y = HEIGH / 2;
}

void initFood()
{
	food.x = rand() % WIDE;
	food.y = rand() % HEIGH;
}
void wallUI()
{
	//画墙
	COORD coord;
	coord.X = 0;
	coord.Y = HEIGH;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	int wide = WIDE;
	while (wide--)
	{
		putchar('^');
	}
	int heigh = HEIGH + 1;
	while (heigh--)
	{
		coord.X = WIDE;
		coord.Y = heigh;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		putchar('|');
	}
}
void initUI()//画蛇贴食
{
	COORD coord;
	for (int i = 0; i < snake.size; i++)
	{
		coord.X = snake.body[i].x;
		coord.Y = snake.body[i].y;
		// printf("%d %d", coord.X, coord.Y);
		/*coord.X = 30;
		coord.Y = 15;*/
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		if (i==0)
		{
			putchar('O');
		} 
		else
		{
			putchar('*');
		}
		
	}
	//画食物

	coord.X = food.x;
	coord.Y = food.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar('#');
	//PCONSOLE_CURSOR_INFO info; 
	//GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),info );
	
	/*coord.X = 0;
	coord.Y = HEIGH;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);*/
	//putchar('*');
	coord.X = lastx;
	coord.Y = lasty;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar(' ');

}
//int 

CurrentScore()//显示当前成绩
{
	COORD coord;
	coord.X = 0;
	coord.Y = HEIGH+2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	printf("当前成绩：%d", score);
}
void playgame()
{
	int speed = 500;
	char key = 'd';
	//判断蛇是否撞墙
	while (snake.body[0].x>=0&& snake.body[0].x<WIDE
		&& snake.body[0].y >= 0 && snake.body[0].y < HEIGH)
	{
		char keyset = key;
		initUI();
		//不阻塞输入
		if (_kbhit())
		{
			key = getch();
		   if (keyset=='a'&&key=='d')//防止掉头  
		   {
			   key = keyset;
		   } 
		   else if (keyset == 'w' && key == 's')
		   {
			   key = keyset;
		   }
		   else if (keyset == 's' && key == 'w')
		   {
			   key = keyset;
		   }
		   else if (keyset == 'd' && key == 'a')
		   {
			   key = keyset;
		   }

		   
		}
		switch (key)
		{
		case 'w':
			kx = 0;
			ky = -1;
			break;
		case 's':
			kx = 0;
			ky = 1;
			break;
		case 'a':
			kx = -1;
			ky = 0;
			break;
		case 'd':
			kx = 1;
			ky = 0;
			break;

		default:
			break;
		}
		//printf("%c", key);
		//蛇撞身体
		for (int i=1;i<snake.size;i++)
		{
			if (snake.body[0].x== snake.body[i].x&&
				snake.body[0].y == snake.body[i].y)//判断是否身体与蛇头相撞
			{
				return;//结束游戏
			}
		}
		if (snake.body[0].x == food.x&&
			snake.body[0].y == food.y)//撞上食物
		{
			//食物消失  身体边长  加分 加速
			initFood();
			snake.size++;
			score+=5;
			if ((speed -= 10) > 0)//对速度调整 并防止小于0
			{
				speed -= 10;
			}
			else
				speed = 10;
			
		}
		//蛇尾坐标
		lastx = snake.body[snake.size - 1].x;
		lasty = snake.body[snake.size - 1].y;

		//蛇移动钱一节身体给后一节复制
		for (int i=snake.size-1;i>0;i--)
		{
			snake.body[i].x = snake.body[i - 1].x;
			snake.body[i].y = snake.body[i - 1].y;
		}
		snake.body[0].x += kx;
		snake.body[0].y += ky;
		Sleep(speed);//调整速度
		//system("cls");
		CurrentScore();//当前分数
	}

	return;
}
