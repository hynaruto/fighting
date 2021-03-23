//整数反转

//https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xnx13t/

//思路:按位取出，注意越界的情况

int reverse(int x)
{
    int result = 0;
    while (x)
    {
        int p = x % 10;
        x /= 10;
        if ((result > INT_MAX / 10) || (result == INT8_MAX / 10) && (p > 7))
            return 0;
        if ((result < INT_MIN/ 10) || (result == INT_MIN / 10) && (p < -8))
            return 0;
        result = result * 10 + p;
    }
    return result;
}