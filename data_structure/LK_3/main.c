//https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xnhhkv/

//旋转图像

//给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
//
//你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。


void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    //从外到内进行顺时针交换
    int circul = (matrixSize + 1) / 2;
    for (int i = 0;i < circul;++i)
    {
        for (int j = i;j < matrixSize - 1 - i;++j)
        {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[matrixSize - j - 1][i];
            matrix[matrixSize - j - 1][i] = matrix[matrixSize - i - 1][matrixSize - j - 1];
            matrix[matrixSize - i - 1] [matrixSize - j - 1] = matrix[j][matrixSize - i - 1];
            matrix[j][matrixSize - i - 1] = tmp;
        }
    }
}