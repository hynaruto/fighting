#include <stdio.h>
#include <vector>
using namespace std;

//行数
#define ROWS 9
//列数
#define COLS 11
//定义直线代价
#define ZXDJ 10
//定义斜线代价
#define XXDJ 14

//定义节点的类型
struct MyPoint{
    int row;
    int col;
    int F;
    int G;
    int H;
    void setF()
    {
        F = G + H;
    }
};

//定义树的节点
struct TreeNode{
    MyPoint           pos; //当前点坐标

    vector<TreeNode*> childs; //存储当前点的孩子节点指针的  数组
    TreeNode*         pParent;//存储当前点的父节点指针的    变量
};

enum direct{p_up,p_down,p_left,p_right,p_lup,p_ldown,p_rup,p_rdown};

//打印地图
void PrintMap(int map[ROWS][COLS])
{
    for (int i = 0;i < ROWS;i++)
    {
        for (int j = 0;j < COLS;j++)
        {
            if (map[i][j] == 0)
            {
                printf("-");
            } else if (map[i][j] == 1)
            {
                printf("*");//*代表墙
            }
        }
        printf("\n");
    }
}

//计算H值 endPos:终点,MyPoint pos:当前点坐标
int GetH(MyPoint endPos,MyPoint pos)
{
    int x = ((endPos.col > pos.col) ? (endPos.col - pos.col) : (pos.col - endPos.col));
    int y = ((endPos.row > pos.row) ? (endPos.row - pos.row) : (pos.row - endPos.row));
    return (x + y) * ZXDJ;
}

//判断是否需要统计

bool needAdd(MyPoint pos,int map[ROWS][COLS],bool PathMap[ROWS][COLS])
{
    if (pos.row >= ROWS || pos.row < 0||
        pos.row >= COLS || pos.col < 0)
    {
        return false;
    }
    if (1 == map[pos.row][pos.col])
        return false;
    if (true == PathMap[pos.row][pos.col])
        return false;
    return true;
}



int main()
{
    //绘制地图,1代表障碍物
    int map[ROWS][COLS] = {{0,0,0,0,0,1,0,0,0,0,0},
                           {0,0,0,0,0,1,0,0,0,0,0},
                           {0,0,0,0,0,1,0,0,0,0,0},
                           {0,0,0,0,0,1,0,0,0,0,0},
                           {0,0,0,0,0,1,0,0,0,0,0},
                           {0,0,0,0,0,1,0,0,0,0,0},
                           {0,0,0,0,0,1,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,1,0,0,0,0,0},
    };
    //辅助地图用来看点坐标是否走过  false:0 没有走过；true：1 走过;
    bool PathMap[ROWS][COLS] = {0};

    //设置起点和终点
    MyPoint begPos = {2,2};
    MyPoint endPos = {4,8};

    //标记起点为走过
    PathMap[begPos.row][begPos.col] = true;

    //创建一颗树，起点是树的根节点
    TreeNode* pNew = new TreeNode;
    memset(pNew,0,sizeof (TreeNode));

    //创建新节点pRoot一直代表树根节点
    TreeNode* pRoot = pNew;
    //新节点用来记录起点
    pRoot ->pos = begPos;

    //创建一个动态数组用来存储   比较的节点
    vector<TreeNode*> arr;

    //寻路
    TreeNode* pCurrent = pRoot;
    TreeNode* pChild = NULL;

    //迭代器
    vector<TreeNode*>::iterator it;
    vector<TreeNode*>::iterator itMin;

    bool isFindEnd = false;

    while (1)
    {
        //找到当前点周围能走的点；
        for (int i = 0;i < 8;i++)
        {
            pChild = new TreeNode;
            memset(pChild,0,sizeof(TreeNode));
            pChild ->pos = pCurrent ->pos;
            switch (i)
            {
                case p_up:
                    pChild ->pos.row--;
                    pChild ->pos.G += ZXDJ;
                    break;
                case p_down:
                    pChild ->pos.row++;
                    pChild ->pos.G += ZXDJ;
                    break;
                case p_left:
                    pChild ->pos.col--;
                    pChild ->pos.G += ZXDJ;
                    break;
                case p_right:
                    pChild ->pos.col++;
                    pChild ->pos.G += ZXDJ;
                    break;
                case p_lup:
                    pChild ->pos.col--;
                    pChild ->pos.row--;
                    pChild ->pos.G += XXDJ;
                    break;
                case p_rup:
                    pChild ->pos.col++;
                    pChild ->pos.row--;
                    pChild ->pos.G += XXDJ;
                    break;
                case p_ldown:
                    pChild ->pos.col--;
                    pChild ->pos.row++;
                    pChild ->pos.G += XXDJ;
                    break;
                case p_rdown:
                    pChild ->pos.col++;
                    pChild ->pos.row++;
                    pChild ->pos.G += XXDJ;
                    break;
                default:
                    break;
            }
            //计算 F，G，H；

            pChild ->pos.H = GetH(endPos,pChild->pos);
            pChild ->pos.setF();

            //入树，入arr数组；

            if (needAdd(pChild ->pos,map,PathMap)){
                //入树；
                pCurrent ->childs.push_back(pChild);
                pChild ->pParent = pCurrent;

                //入arr数组
                arr.push_back(pChild);
                PathMap[pChild ->pos.row][pChild ->pos.col] = true;

            } else{
                delete pChild;
            }
        }
        //从arr数组里找到F值最小的那个点
        itMin = arr.begin();
        for (it = arr.begin();it != arr.end();it ++){
            itMin = (((*itMin)->pos.F > (*it) ->pos.F) ? it : itMin);
        }
        //删除掉，变化成当前点；
        pCurrent = *itMin;
        arr.erase(itMin);
        //判断是否寻路结束
        if (pCurrent -> pos.row == endPos.row&&
            pCurrent -> pos.col == endPos.col){
            isFindEnd = true;
            break;
        }
        if (arr.empty())
            break;
    }
    if (isFindEnd){
        printf("找到终点\n");
        while (pCurrent){
            printf("(%d,%d)",pCurrent ->pos.row,pCurrent ->pos.col);
            pCurrent = pCurrent ->pParent;
        }
        printf("\n");
    }

    //打印地图
    PrintMap(map);




    return 0;
}