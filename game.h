#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW  3//行
#define COL  3//列


//函数声明
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);

//四种状态
//玩家赢-'*'  电脑赢-'#' 平局-'Q'  继续-'C'
char Iswin(char board[ROW][COL], int row, int col);

//判断棋盘满没满  1-满  0-没满
int IsFull(char board[ROW][COL], int row, int col);