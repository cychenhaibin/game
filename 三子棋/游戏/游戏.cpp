#define _CRT_SECURE_NO_WARNINGS 1

#include"��Ϸ.h"

void InitBoard(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			arr[i][j] = ' ';
		}
	}
}
void DisplayBoard(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0;i < row;i++)
	{
		//1. ��ӡһ�е�����
		int j = 0;
		for (j = 0;j < col;j++)
		{
			printf(" %c ", arr[i][j]);
			if(j<col-1)
			printf("|");
		}
		printf("\n");
		//2. ��ӡ�ָ���
		if (i < row - 1) 
		{
			for (j = 0;j < col;j++)
			{
				printf("---");
				if (j < col - 1) 
				{
					printf("|");
				}
				
			}
			printf("\n");
		}
		
	}
}
void PlayerMove(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("����ߣ�>\n");
	while (1)
	{
		printf("������Ҫ�µ����꣺>");
		scanf("%d%d", &x, &y);
		//�ж�x,y����ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (arr[x - 1][y - 1] == ' ')
			{
				arr[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�����걻ռ��\n");
			}
		}
		else
		{
			printf("����Ƿ�������������;\n");
		}
	}
}
void ComputerMove(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����ߣ�>");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (arr[x][y] == ' ')
		{
			arr[x][y] = '#';
			break;
		}
	}
}
//����1��ʾ��������
//����0��ʾ����û��
int IsFull(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			if (arr[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char IsWin(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	//������
	for (i = 0;i < row;i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][1] != ' ')
		{
			return arr[i][1];
		}
	}
	//������
	for (i = 0;i < col;i++)
	{
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[1][i] != ' ')
		{
			return arr[1][i];
		}
	}
	//�Խ���
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != ' ')
	{
		return arr[1][1];
	}
	if (arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2] && arr[1][1] != ' ')
	{
		return arr[1][1];
	}
	//�ж��Ƿ�ƽ��
	if (1 == IsFull(arr, ROW, COL))
	{
		return 'Q';
	}
	else
	{
		return 'C';
	}
}