



//https://ac.nowcoder.com/acm/problem/16422

//链接：https://ac.nowcoder.com/acm/problem/16422
//来源：牛客网
//
//图书馆中每本书都有一个图书编码，可以用于快速检索图书，这个图书编码是一个正整数。
//
//每位借书的读者手中有一个需求码，这个需求码也是一个正整数。如果一本书的图书编码恰好以读者的需求码结尾，那么这本书就是这位读者所需要的。
//
//小 D 刚刚当上图书馆的管理员，她知道图书馆里所有书的图书编码，她请你帮她写一个程序，对于每一位读者，求出他所需要的书中图书编码最小的那本书，如果没有他需要的书，请输出-1。



#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution
{
public:
    int FindBooks(vector<int> &nums)
    {
        int n,q = 0;
        int nums_len,num;
        //代表图书馆里书n的数量和读者q的数量
        cin>> n>> q;
        //n 行，每行包含一个正整数，代表图书馆里某本书的图书编码
        for (int i = 0;i < n;++i)
        {
            cin >> nums_len;
            nums[i] = nums_len;
        }
        //排序
        sort(nums.begin(),nums.begin() + n);
        //q 行，每行包含两个正整数.第一个正整数:读者的需求码的长度，第二个正整数:读者的需求码
        for (int i = 0;i < q;++i)
        {
            int flag = 0;
            cin>> nums_len >> num;
            int m = (int) pow(10,nums_len);
            for (int j = 0;j < n;++j)
            {
                if (num == nums[j] % m)
                {
                    cout<< nums[j] <<endl;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                cout<< -1 <<endl;
        }
        return 0;
    }
};

int main()
{
    std::vector<int> nums(1000,0);
    Solution S;
    S.FindBooks(nums);
    return 0;
}