#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW  3//��
#define COL  3//��


//��������
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);

//����״̬
//���Ӯ-'*'  ����Ӯ-'#' ƽ��-'Q'  ����-'C'
char Iswin(char board[ROW][COL], int row, int col);

//�ж�������û��  1-��  0-û��
int IsFull(char board[ROW][COL], int row, int col);