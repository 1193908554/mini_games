#define _CRT_SECURE_NO_WARNINGS 1//用于函数安全问题

#include"game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
//___|___|___
//___|___|___
//   |   |
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (int k = 0; k < col; k++)
			{
				printf("---");
				if (k < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
	/*for (int i = 0; i < row; i++)自己想的
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if(j < col - 1)
				printf("|");
		}
		printf("\n");
		for (int k = 0; k < col && i < row - 1; k++)
		{
			printf("---");
			if(k < col - 1)
				printf("|");
		}
		printf("\n");
	}*/
}


void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走:>\n");
	while (1)
	{
		printf("请输入要下的坐标：>\n");
		scanf("%d%d", &x, &y);
		//判断xy坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用，请重新输入！\n");
			}
		}
		else
		{
			printf("坐标非法,请重新输入!\n");
		}
	}
}



void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走:>\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		//判断xy坐标的合法性
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
		
	}
}


//判断棋盘满没满  1-满  0-没满
int IsFull(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}


char Iswin(char board[ROW][COL], int row, int col)
{
	int sign = 1;

	for (int i = 0; i < row; i++)//判断行
	{
		sign = 1;//0-没结果  1-赢
		for (int j = 0; j < col - 1; j++)
		{
			if (board[i][j] != board[i][j + 1] || board[i][j] == ' ')
			{
				sign = 0;
			}
			if (sign == 0)
			{
				break;
			}
		}
		if (sign == 1)//有一方已经赢了
		{
			return board[i][i];
		}
	}
	for (int j = 0; j < col; j++)//判断列
	{
		sign = 1;//0-没结果  1-赢
		for (int i = 0; i < row - 1; i++)
		{
			if (board[i][j] != board[i + 1][j] || board[i][j] == ' ')
			{
				sign = 0;
			}
			if (sign == 0)
			{
				break;
			}
		}
		if (sign == 1)//有一方已经赢了
		{
			return board[j][j];
		}
	}
	sign = 1;
	for (int i = 0; i < row - 1; i++)//斜向下
	{
		if (board[i][i] != board[i + 1][i + 1] || board[i][i] == ' ')
		{
			sign = 0;
		}
		if (sign == 0)
		{
			break;
		}
	}
	if (sign == 1)//有一方已经赢了
	{
		return board[1][1];
	}
	sign = 1;
	for (int i = 0; i < row - 1; i++)//斜向上
	{
		if (board[row - 1 - i][i] != board[row - 1 - i - 1][i + 1] || board[row - 1 - i][i] == ' ')
		{
			sign = 0;
		}
		if (sign == 0)
		{
			break;
		}
	}
	if (sign == 1)//有一方已经赢了
	{
		return board[1][1];
	}

	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}

