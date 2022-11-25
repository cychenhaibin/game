#define ROW 3
#define COL 3

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//声明
void InitBoard(char arr[ROW][COL], int row, int col);
void DisplayBoard(char arr[ROW][COL],int row,int col);
void PlayerMove(char arr[ROW][COL], int row, int col);
void ComputerMove(char arr[ROW][COL],int row ,int col );

//告诉四种游戏状态
//玩家赢--- '*'
//电脑赢--- '#'
//平局  --- 'Q'
//继续  --- 'C'
char IsWin(char arr[ROW][COL], int row, int col);
