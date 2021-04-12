



//https://leetcode-cn.com/problems/n-queens-ii/submissions/

//52. N皇后 II



#include<iostream>
#include<vector>
#include <string>
using namespace std;
class Solution {
public:
    bool isvalid(int &row,int &col,vector<string> &charboard,int n)
    {
        for (int i = 0;i < row;++i)
        {
            if (charboard[i][col] == 'Q')
                return false;
        }
        for (int i = row - 1,j = col - 1;i >= 0 && j >= 0;--i,--j)
        {
            if (charboard[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1,j = col + 1;i >= 0 && j < n;--i,++j)
        {
            if (charboard[i][j] == 'Q')
                return false;
        }
        return true;
    }
public:
    void backtracking(const int n,int row,int &count,vector<string> &charboard)
    {
        if (row == n)
        {
            ++count;
            return;
        }
        for (int col = 0;col < n;++col)
        {
            if (isvalid(row,col,charboard,n))
            {
                charboard[row][col] = 'Q';
                backtracking(n,row+1,count,charboard);
                charboard[row][col] = '.';
            }
        }
    }
public:
    int totalNQueens(int n)
    {
        std::vector<std::string> charboard(n,std::string(n,'.'));
        int count = 0;
        backtracking(n,0,count,charboard);
        return count;
    }
};

int main()
{
    Solution S;
    int result = S.totalNQueens(10);
    cout<<result<<endl;
    return 0;
}



