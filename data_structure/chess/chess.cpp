//
// Created by 胡杨 on 2020/10/30.
//
#include "chess.h"

//菜单实现函数
void ShowMenu()
{
    printf("***********************\n");
    printf("*******1.Play**********\n");
    printf("*******2.Exit**********\n");
    printf("***********************\n");
    printf("请选择: ");
}
//打印棋盘
void ShowBoard(char board[][COL],int row,int col)
{
    printf(" | 1 | 2 | 3 |\n");
    printf("---------------\n");
    for (int i = 0;i < row;i++)
    {
        printf("\n %d | ",i + 1);
        for (int j = 0;j < col;j++)
        {
            printf(" %c |",board[i][j]);
        }
    }
    printf("\n");
}
//用户移动
void PlayerMove(char board[][COL],int row,int col)
{
    int x,y = 0;
    while(1){
        printf("请输入棋子的点坐标:");
        scanf("%d %d",&x,&y);
        //判断越界问题
        if (x < 1 || x > 3 || y < 1 || y > 3)
        {
            printf("输入有误\n");
            continue;
        }
        if (board[x - 1][y - 1] != ' ')
        {
            printf("棋子存在！\n");
            continue;
        }
        board[x - 1][y - 1] = PLEAR_COLOR;
        return;
    }
}
//电脑随机移动
void ComputerMove(char board[][COL],int row,int col)
{
   while (1)
   {
       int x = rand() % row;
       int y = rand() % col;
       if (board[x][y] == ' ')
       {
           board[x][y] = COMPUTER_COLOR;
           break;
       }
   }
}

//判断
char Judge(char board[][COL],int row,int col)
{
    //判断谁结果
    for (int i = 0;i < row;i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            return board[i][0];
        }
    }
    for (int i = 0;i < col;i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[i][0] != ' ')
        {
            return board[0][i];
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
    {
        return board[1][1];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
    {
        return board[1][1];
    }
    //继续
    for (int i = 0;i < row;i++)
    {
        for (int j = 0;j < col;j++)
        {
            if (board[i][j] ==' ')
            {
                return 'N';
            }
        }
    }
    //平局
    return 'P';
}
//游戏实现
void Game()
{
    char board[ROW][COL];
    //随机数种子
    srand((unsigned long)time(NULL));
    //棋盘初始化
    memset(board,' ', sizeof(board));
    char win = '\0';
    do{
        //打印棋盘
        ShowBoard(board,ROW,COL);
        //用户先走;
        PlayerMove(board,ROW,COL);
        //判断
        win = Judge(board,ROW,COL);
        if (win != 'N')
        {
            break;
        }
        //电脑走;
        ComputerMove(board,ROW,COL);
        //判断
        win = Judge(board,ROW,COL);
        if (win != 'N')
        {
            break;
        }
    }while (1);
    switch (win)
    {
        case PLEAR_COLOR:
            printf("恭喜你，你赢了！\n");
            break;
        case COMPUTER_COLOR:
            printf("很遗憾，你输了！\n");
            break;
        case 'P':
            printf("平局！");
            break;
        default:
            break;
    }

}