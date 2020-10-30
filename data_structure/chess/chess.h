//
// Created by 胡杨 on 2020/10/30.
//

#ifndef CHESS_CHESS_H
#define CHESS_CHESS_H

#endif //CHESS_CHESS_H
#define ROW 3
#define COL 3
#define PLEAR_COLOR    'X'
#define COMPUTER_COLOR 'O'
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <time.h>


void ShowMenu();
void Game();
void ShowBoard(char board[][COL],int row,int col);
void PlayerMove(char board[][COL],int row,int col);
char Judge(char board[][COL],int row,int col);
void ComputerMove(char board[][COL],int row,int col);