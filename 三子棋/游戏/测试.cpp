#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"��Ϸ.h"
void menu()
{
	printf("1. PLAY    0. EXIT");

}
//��Ϸ�������㷨ʵ��
void game()
{
	char ret = 0;
	//�������߳���������Ϣ
	char arr[ROW][COL] = { 0 }; //ȫ���ո�
	//��ʼ������
	InitBoard(arr, ROW, COL);
	//��ӡ����
	DisplayBoard(arr, ROW, COL);
	//����
	while (1)
	{
		//�������
		PlayerMove(arr, ROW, COL);
		DisplayBoard(arr, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret = IsWin(arr, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		//��������
		ComputerMove(arr, ROW, COL);
		DisplayBoard(arr, ROW, COL);
		//�жϵ����Ƿ�Ӯ
		ret = IsWin(arr,ROW,COL);
		if (ret != 'c')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			printf("������\n");
			break;
		case 2:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("����������������룻");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}