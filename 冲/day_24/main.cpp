#include <iostream>
#include <vector>
using namespace std;
using namespace std;
class Solution
{
public:
    vector<pair<int,int>>path_cur;
    vector<pair<int,int>>path_best;
public:
    void backtracking(int i,int j,int &N,int &M,vector<vector<int>> &maze)
    {
        maze[i][j] = 1;
        path_cur.push_back({i,j});
        if (i == N - 1 && j == M - 1)
        {
            if (path_best.empty() || path_cur.size() < path_best.size())
                path_best = path_cur;
        }
        if (i - 1 >= 0 && maze[i - 1][j] == 0)
            backtracking(i - 1, j,N,M,maze);
        if (i + 1 < N && maze[i + 1][j] == 0)
            backtracking(i + 1, j,N,M,maze);
        if (j - 1 >= 0 && maze[i][j - 1] == 0)
            backtracking(i, j - 1,N,M,maze);
        if (j + 1 < M && maze[i][j + 1] == 0)
            backtracking(i, j + 1,N,M,maze);
        maze[i][j] = 0;
        path_cur.pop_back();
    }
public:
    vector<pair<int,int>> dp(int &N,int &M,vector<vector<int>> &maze)
    {
        backtracking(0, 0,N,M,maze);
        return path_best;
    }
};
int main()
{
    Solution S;
    int N,M;
    while (cin >> N >> M)
    {

        vector<vector<int>> maze(N,vector<int>(M));
        for (int i = 0;i < N;++i)
        {
            for (int j = 0;j < M;++j)
                cin>>maze[i][j];
        }
        vector<pair<int,int>> ans = S.dp(N,M,maze);
        for (auto e : ans)
            cout<<'('<<e.first<<','<<e.second<<')'<<endl;
    }
    return 0;
}

/*
class Bonus {
public:
    int getMost(vector<vector<int> > board)
    {
        //dp[i][j]表示当前位置价值最高的礼物
        vector<vector<int>> dp(board.size(),vector<int>(board.size()));
        //base case;
        dp[0][0] = board[0][0];
        for (int i = 1;i < board.size();++i)
        {
            dp[0][i] = dp[0][i - 1] + board[0][i];
        }
        for (int i = 1;i < board.size();++i)
            dp[i][0] = dp[i - 1][0] + board[i][0];
        for (int i = 1;i < board.size();++i)
        {
            for (int j = 1;j < board.size();++j)
                dp[i][j] = max(dp[i - 1][j],dp[i][j - 1])+ board[i][j];
        }
        return dp[board.size() - 1][board.size() - 1];
    }
};
int main()
{
    vector<vector<int>> board;
    Bonus s;
    cout<<s.getMost(board)<<endl;
    return 0;
}
*/