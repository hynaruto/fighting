//https://leetcode-cn.com/problems/n-queens/submissions/

//51. N 皇后


#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> result;
public:
    bool isvalid(int row,int col,vector<string> &charboard,int n)
    {
        //剪枝,检查列
        for (int i = 0;i < row;++i)
        {
            if (charboard[i][col] == 'Q')
                return false;
        }
        //判断主对角线
        for (int i = row - 1,j = col - 1;i >= 0 && j >= 0;--i,--j)
        {
            if (charboard[i][j] == 'Q')
                return false;
        }
        //判断副对角线
        for (int i = row - 1,j = col + 1;i >= 0 && j < n;i--,j++)
        {
            if (charboard[i][j] == 'Q')
                return false;
        }
        return true;
    }
public:
    void backtracking(int n,int row,vector<string> &charboard)
    {
        //递归出口
        if (n == row)
        {
            result.push_back(charboard);
            return;
        }
        //单层循环
        for (int col = 0;col < n;++col)
        {
            if (isvalid(row,col,charboard,n))
            {
                charboard[row][col] = 'Q';
                backtracking(n,row + 1,charboard);
                //回溯
                charboard[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n)
    {
        std::vector<std::string> charboard(n,std::string(n,'.'));
        backtracking(n,0,charboard);
        return result;
    }
};