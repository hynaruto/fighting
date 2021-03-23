
//https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2f9gg/


//题目:有效的数独



//思路:使用一个check数组进行记录数字是否出现，只用一遍遍历即可。
//check[3][9][9]的[3]表示是以行进行判断、以列进行判断和以块进行判断；[9]代表是第几行/第几列/第几块；然后最后一个[9]表示哪个数字。
//每遍历一个新的数据后，将数据以行、列和块三个方式存入数组，并将其置1。
//每次获得一个新的数据，就判断之前是否置1，若为1，则说明之前这个数据在当前行、列或者是块中出现过，返回false
bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int check[3][9][9] = {0};
    int num,chunk;
    int i, j;
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            if(board[i][j] == '.')
                continue;
            else
            {
                num = (int)(board[i][j] - '1');
                chunk = i / 3 * 3 + j / 3;
                if(check[0][i][num] == 1 || check[1][j][num] == 1 || check[2][chunk][num] == 1)
                    return false;

                check[0][i][num] = 1;
                check[1][j][num] = 1;
                check[2][chunk][num] = 1;
            }
        }
    }
    return true;
}