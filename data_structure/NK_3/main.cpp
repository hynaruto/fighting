//https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded?tpId=37&&tqId=21296&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//计算一年的第几天
#include <iostream>
using namespace std;
//思路:把每个月的1号是一年的第几天列举出来做加法
int main()
{
    int y,m,d;
    int arr[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    while (cin>>y>>m>>d)
    {
        int day = arr[m - 1] + d;
        if (m > 2 &&  ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
            day+=1;
        cout<<day<<endl;
    }
    return 0;
}