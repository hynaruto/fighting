//https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2cv1c/
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    //如果最后一位不是9，没有进位
    for (int i = digitsSize - 1;i >= 0;--i)
    {
        if (digits[i] != 9)
        {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }else{
            //最后一位是9
            digits[i] = 0;
        }
    }
    int *arr = (int*)malloc(sizeof(int) * (digitsSize + 1));
    for (int i = 1;i < digitsSize + 1;++i)
    {
        arr[i] = 0;
    }
    arr[0] = 1;
    *returnSize = (digitsSize + 1);
    return arr;
}