#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"游戏.h"
void menu()
{
	printf("1. PLAY    0. EXIT");

}
//游戏的整个算法实现
void game()
{
	char ret = 0;
	//数组存放走出的棋盘信息
	char arr[ROW][COL] = { 0 }; //全部空格
	//初始化棋盘
	InitBoard(arr, ROW, COL);
	//打印棋盘
	DisplayBoard(arr, ROW, COL);
	//下棋
	while (1)
	{
		//玩家下棋
		PlayerMove(arr, ROW, COL);
		DisplayBoard(arr, ROW, COL);
		//判断玩家是否赢
		ret = IsWin(arr, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		//电脑下棋
		ComputerMove(arr, ROW, COL);
		DisplayBoard(arr, ROW, COL);
		//判断电脑是否赢
		ret = IsWin(arr,ROW,COL);
		if (ret != 'c')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			printf("三子棋\n");
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入；");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}