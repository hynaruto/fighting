#include <iostream>
#include<vector>
using namespace std;


//手套问题
//举例，在2，3，4，5的序列中任意找3个数求和，保证没有其他和大于它
//我们一定会选择3，4，5
//但是要找一个整数比其中任意三个数的和都大，且要为最小的一个
//（（2 + 3 + 4 + 5） - 2 ） + 1，即可符合上述条件

//思路:
//1.题目中有最差情况，就是左手手套没有，或者右手手套没有，这样我们必须把这个颜色的手套全部拿走
//2.还有一种情况就是要在左手和右手中找出能够覆盖全部颜色的最小数量
//3.判断左右两边哪一边需要拿的数量最小就拿哪一边，然后在另一边随便拿一个就行
class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right)
    {
        int left_sum = 0,left_min = INT_MAX;
        int right_sum = 0,right_min = INT_MAX;
        int sum = 0;
        for (int i = 0;i < n;++i)
        {
            //左边没有或者右边没有
            if (left[i] * right[i] == 0)
                //最坏情况，全部拿走
                sum += left[i] + right[i];
            else{
                left_sum += left[i];
                right_sum += right[i];
                left_min = min(left[i],left_min);
                right_min = min(right[i],right_min);
            }
        }
        return sum + min(left_sum - left_min + 1,right_sum - right_min + 1) + 1;
    }
};

int main()
{
    int n = 4;
    vector<int> left{0,7,1,6};
    vector<int> right{1,5,0,6};
    Gloves g;
    cout<<g.findMinimum(n,left,right)<<endl;
}

//求一个数中二进制中1的个数
/*
#include<iostream>
#include<bitset>
using namespace std;
int main()
{
    int n = 0;
    while (cin >> n)
    {
        int count = 0;
        while (n)
        {
            if (n & 1)
                count++;
            n >>= 1;
        }
        cout<<count<<endl;
    }
    return 0;
}
/*
int main()
{
    int n = 0;
    while (cin >> n)
    {
        bitset<32> bt(n);
        cout<<bt.count()<<endl;
    }
    return 0;
}
*/
*/