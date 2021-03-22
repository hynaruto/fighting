//https://www.nowcoder.com/practice/b1f7a77416194fd3abd63737cdfcf82b?tpId=69&&tqId=29669&rp=1&ru=/activity/oj&qru=/ta/hust-kaoyan/question-ranking
//打印日期
#include <iostream>
using namespace std;
int main()
{
    int arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int y,n;
    while(cin>>y>>n)
    {
        int m = 0,p = 0;
        if ((y%4==0 && y%100!=0) || (y%400==0))
            arr[1] += 1;
        for (int i = 0;i < 12;++i)
        {
            m = i + 1,n += arr[i];
            if (p >= n)
            {
                p -= arr[i];
                p = n - p;
                break;
            }
        }
        if (m/10 == 0)
            cout<<y<<"-0"<<m;
        else
            cout<<y<<"-"<<m;
        if (p/10==0)
            cout<<""-0<<p<<endl;
        else
            cout<<"-"<<p<<endl;
        arr[1] = 28;
    }
    return 0;
}