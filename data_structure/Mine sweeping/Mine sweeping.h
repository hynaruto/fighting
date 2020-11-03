//
// Created by 胡杨 on 2020/10/31.
//

#ifndef MINE_SWEEPING_MINE_SWEEPING_H
#define MINE_SWEEPING_MINE_SWEEPING_H

#endif //MINE_SWEEPING_MINE_SWEEPING_H

#include <stdio.h>
#include <cstring>
#include <time.h>
#include <cstdlib>
#define ROW  12
#define COL  12
#define NUMS 20
void Menu();
void Game();
void InitBoard_S(char board[][COL],int row,int col, char set);
void InitBoard_M(char board[][COL],int row,int col, char set);
void ShowBoard(char board[][COL],int row,int col);
void SetMine(char board[][COL],int row,int col);
int GetNums(char borad[][COL],int row,int col);
