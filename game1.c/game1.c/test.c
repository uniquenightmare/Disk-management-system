#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include"game.h"
#include<time.h>
void game()
{
	char board[ROW][COL];
	char ret ;
	
	
	setboard(board, ROW, COL);
	Display(board, ROW, COL);
	do
	{
		playerin(board, ROW, COL);
		Display(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		computerin(board, ROW, COL);
		Display(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	} while (1);
	if(ret == '#')
	{
		printf("����Ӯ\n");
	}
		
	else if (ret == '*')
	{
		printf("���Ӯ\n");

	}
	else if (ret == 'Q')
	{

		printf("ƽ��\n");
	}
   

	
}
void menu()
{
	printf("*************************\n");
	printf("*****     1.play    *****\n");
	printf("*****     0.exit    *****\n");
	printf("*************************\n");

}
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
	menu();
	printf("�����ѡ��=>\n");
	scanf("%d", &input);
	switch (input)
	{
	case 1: 
		game();
		break;
	case 0:
		printf("�ѳɹ��˳���Ϸ\n");
		break;
	default:
		printf("�������,������ѡ��\n");
		break;
	}

	} while (input);
	
}
int main()
{
	test();
	system("pause");
	return 0;
}
