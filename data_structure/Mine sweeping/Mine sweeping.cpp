//
// Created by 胡杨 on 2020/10/31.
//

#include "Mine sweeping.h"

void Menu()
{
    printf("************************\n");
    printf("*******1.Play***********\n");
    printf("*******2.Exit***********\n");
    printf("************************\n");
    //printf("请选择:");
}

void SetMine(char board[ROW][COL],int row,int col)
{
    int nums = NUMS;
    while (nums)
    {
        int x = rand() % 10 + 1;
        int y = rand() % 10 + 1;
        if (board[x][y] == '0')
        {
            board[x][y] = '1';
            nums--;
        }
    }
}
//获取点周围有多少颗雷
int GetNums(char borad[][COL],int row,int col,int x,int y)
{
    return borad[x - 1][y - 1] + borad[x - 1][y] + borad[x - 1][y + 1] + borad[x][y + 1] + borad[x + 1][y + 1] + borad[x + 1][y] + borad[x + 1][y + 1] + borad[x][y - 1] - 8 * '0';
}

//绘制棋盘
void Show_Board(char board[][COL],int row,int col)
{
    for (int i = 1;i < col - 1;i++)
    {
        printf(" %2d",i);
    }
    printf("\n");
    for (int i = 1;i < row - 1;i++)
    {
        printf("%2d|",i);
        for (int j = 1;j < col - 1;j++)
        {
            printf("%c |",board[i][j]);
        }
        printf("\n");
    }
}
void expand(char MineBoard[][COL], char ShowBoard[][COL],int x,int y)
{
    if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
    {
        int count = GetNums(MineBoard,ROW,COL,x,y);
        if (count == '0')
        {
            ShowBoard[x][y] = ' ';
            if (ShowBoard[x - 1][y - 1] ==  '*')
            {
                expand(MineBoard,ShowBoard,x -1 ,y -1 );
            }
            if (ShowBoard[x - 1][y] == '*')
            {
                expand(MineBoard,ShowBoard,x - 1,y);
            }
            if (ShowBoard[x - 1][y + 1] == '*')
            {
                expand(MineBoard,ShowBoard,x - 1,y + 1);
            }
            if (ShowBoard[x][y - 1] == '*')
            {
                expand(MineBoard,ShowBoard,x,y - 1);
            }
            if (ShowBoard[x][y + 1] == '*')
            {
                expand(MineBoard,ShowBoard,x,y + 1);
            }
            if (ShowBoard[x + 1][y - 1] == '*')
            {
                expand(MineBoard,ShowBoard,x + 1,y - 1);
            }
            if (ShowBoard[x + 1][y] == '*')
            {
                expand(MineBoard,ShowBoard,x + 1,y);
            }
            if (ShowBoard[x + 1][y + 1] == '*')
            {
                expand(MineBoard,ShowBoard,x + 1,y + 1);
            }
        } else{
            ShowBoard[x][y] = count;
        }
    }
}

void Game()
{
    //随机数种子
    srand((unsigned long)time((NULL)));
    //用户界面（排查出雷的信息）
    char ShowBoard[ROW][COL] = {0};
    //布置雷的界面
    char MineBoard[ROW][COL] = {0};
    //初始化棋盘
    memset(ShowBoard,'*', sizeof(ShowBoard));
    memset(MineBoard,'0', sizeof(MineBoard));
    //布置雷的个数（20个）用'1'表示
    SetMine(MineBoard,ROW,COL);
    int x,y = 0;
    int count = (ROW - 2) * (COL - 2) - NUMS;
    do{
        Show_Board(ShowBoard,ROW,COL);
        printf("请输入坐标：");
        scanf("%d %d",&x,&y);
        if (x < 1 || x > ROW - 2 || y < 1 || y > COL - 2)
        {
            printf("输入位置越界，请重新输入！");
            continue;
        }
        if (ShowBoard[x][y] != '*')
        {
            printf("该位置已经排除！");
            continue;
        }
        //开始排雷
        if (MineBoard[x][y] == '1')
        {
            break;
        } else{
            expand(MineBoard,ShowBoard,x,y);
        }
        int num = GetNums(MineBoard,ROW,COL,x,y);
        ShowBoard[x][y] = num + '0';
        count--;
    }while (count > 0);
    if (count > 0)
    {
        printf("你被炸死了！\n");
    } else{
        printf("恭喜过关！\n");
    }
}