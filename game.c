#define _CRT_SECURE_NO_WARNINGS 1//���ں�����ȫ����

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
	/*for (int i = 0; i < row; i++)�Լ����
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
	printf("�����:>\n");
	while (1)
	{
		printf("������Ҫ�µ����꣺>\n");
		scanf("%d%d", &x, &y);
		//�ж�xy����ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�����걻ռ�ã����������룡\n");
			}
		}
		else
		{
			printf("����Ƿ�,����������!\n");
		}
	}
}



void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("������:>\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		//�ж�xy����ĺϷ���
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
		
	}
}


//�ж�������û��  1-��  0-û��
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

	for (int i = 0; i < row; i++)//�ж���
	{
		sign = 1;//0-û���  1-Ӯ
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
		if (sign == 1)//��һ���Ѿ�Ӯ��
		{
			return board[i][i];
		}
	}
	for (int j = 0; j < col; j++)//�ж���
	{
		sign = 1;//0-û���  1-Ӯ
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
		if (sign == 1)//��һ���Ѿ�Ӯ��
		{
			return board[j][j];
		}
	}
	sign = 1;
	for (int i = 0; i < row - 1; i++)//б����
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
	if (sign == 1)//��һ���Ѿ�Ӯ��
	{
		return board[1][1];
	}
	sign = 1;
	for (int i = 0; i < row - 1; i++)//б����
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
	if (sign == 1)//��һ���Ѿ�Ӯ��
	{
		return board[1][1];
	}

	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}

