#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include"game.h"
#include<stdlib.h>

void setboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
	//memset(board, ' ', row*col*sizeof(char));
}
void Display(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
for (j = 0; j <  col; j++)
	{
		printf(" %c ",board[i][j]);
		if (j < col-1)
		{
			printf("|");
		}
	}
	printf("\n");
	for (j = 1; j <= row; j++)
	{
		if (i < row-1)
		{
            printf("--- ");
		}
		
		
	}
	printf("\n");

	}
	
}
void playerin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("玩家玩\n");
	
	while (1)
	{
       printf("请输入坐标=>\n");
	   scanf("%d%d", &i, &j);
		if ((i >= 1) && (i <= row) && (j >= 1) && (j <= col))
		{
			if (board[i - 1][j - 1] == ' ')
			{
				board[i - 1][j - 1] = '*';
				break;
			}
			else
			{
				printf("此处以下过\n");
			}
		}
		else
		{
			printf("坐标输入错误\n");
		}
	}
}
void computerin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0; 
	printf("电脑玩\n");
	while (1)
	{
		i = rand() % 3;
		j = rand() % 3;
		if (board[i][j] == ' ')
		{
			board[i][j] = '#';
			break;
		}
	}
}
static int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;

}
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][1] != ' '))
			return board[i][1];
	}	
	for (j = 0; j < col; j++)
	{
		if ((board[0][j] == board[1][j]) && (board[1][j] == board[2][j]) && (board[1][j] != ' '))
			return board[i][1];
	}
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if ((board[2][0] == board[1][1]) && (board[1][1] == board[0][2]) && board[1][1] != ' '
		)
	{
		return board[1][1];
	}
	if (IsFull(board,row,col))
	{
		return 'Q';
	}
	return'C';
}
