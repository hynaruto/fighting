//https://www.nowcoder.com/practice/ccb7383c76fc48d2bbc27a2a6319631c?tpId=62&&tqId=29468&rp=1&ru=/activity/oj&qru=/ta/sju-kaoyan/question-ranking
//日期差值
#include <iostream>
using namespace std;

//思路:设定一个基准值0000年0月1日，让年份都与基准值相减，再将各自的天数相减

//1月到12月的天数
int arr[12]={0,31,59,90,120,151,181,212,243,273,304,334};

int Date_del(int y,int m,int d)
{
    // 计算0-y年的天数
    int yearDay = y*365+y/4-y/100+y/400;
    // 计算到0-m月的天数
    int monthDay = arr[m-1];

    if(m > 2 && ((y%4 == 0 && y%100 != 0) || y%400==0))
        monthDay += 1;

    return yearDay + monthDay + d;
}


int main()
{
    int _year,_month,_day;
    scanf("%4d%2d%2d",&_year,&_month,&_day);
    int n1 = Date_del(_year,_month,_day);

    int year,month,day;
    scanf("%4d%2d%2d",&year,&month,&day);
    int n2 = Date_del(year,month,day);

    cout<<abs(n1-n2)+1<<endl;
    return 0;
}
