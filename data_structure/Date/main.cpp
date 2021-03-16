#include<iostream>
#include <assert.h>
using namespace std;

class Date
{
    friend ostream& operator<<(ostream& out,const Date &d);
    friend istream& operator>>(istream& is,Date &d);
public:
    //构造函数
    explicit Date (int year = 1900,int month = 1,int day = 1)
    {
        _year = year,_month = month,_day = day;
        //参数检测
        if ((year >= 1900) && (month >= 1 && month <= 12) && (day >= 1 && day <= Day_Of_Month(year,month)))
        {
            _year = year,_month = month,_day = day;
        }else
        {
            cout<<"日期非法"<<endl;
            _year = 1900,_month = 1,_day = 1;
        }
    }
    //拷贝构造函数
    Date (const Date& d) : _year(d._year),_month(d._month),_day(d._day)
    {}

    //析构函数
    ~Date()
    = default;


public:
    //操作符重载
    Date& operator=(const Date &d);
    bool operator==(const Date &d);
    bool operator!=(const Date &d);
    bool operator>(const Date &d);
    bool operator>=(const Date &d);
    bool operator<(const Date &d);
    bool operator<=(const Date &d);
    Date operator+(int day);
    Date& operator+=(int day);
    Date operator-(int day);
    int operator-(const Date &d); //两个日期相隔天数
    Date& operator-=(int day);
    Date& operator++();
    Date operator++(int);
    Date& operator--();
    Date operator--(int);


public:
    //判断参数是否合法
    bool IsValid()
    {
        return !(_year < 1 || (_month < 1 || _month > 12) || (_day < 1 || _day > Day_Of_Month(_year, _month)));
    }

public:
    int Day_Of_Month(int year,int month)
    {
        //检查合法性
       assert(month > 0 && month <= 12);
       int arr[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
       int day;
       if (!(Is_Leap_Year()) && month == 2)
        {
           _day = arr[month] - 1;
        }
        day = arr[month];
        return day;
    }

    bool Is_Leap_Year()
    {
        if ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0)
               return true;
        return false;
    }
private:
    int _year,_month,_day;
};

ostream& operator<<(ostream& out,const Date &d)
{
    out<<d._year<<"-"<<d._month<<"-"<<d._day<<endl;
    return out;
}

istream& operator>>(istream& is, Date &d)
{
    cout<<"输入日期:";
    is >>d._year;
    is >>d._month;
    is >>d._day;
    return is;
}

//赋值
Date& Date::operator=(const Date &d)
{
    if (*this != d)
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }
    return *this;
}

bool Date::operator==(const Date &d)
{
    return (_year == d._year) && (_month == d._month) && (_day == d._day);
}

bool Date::operator!=(const Date &d)
{
    return !(*this == d);
}

bool Date::operator>(const Date &d)
{
    return (_year > d._year) || ((_year == d._year) && (_month > d._month)) || ((_year == d._year) && (_month == d._month) && (_day > d._day));
}

bool Date::operator>=(const Date &d)
{
    return (*this == d) || (*this > d);
}

bool Date::operator<(const Date &d)
{
    return (_year < d._year) || ((_year == d._year) && (_month < d._month)) || ((_year == d._year) && (_month == d._month) && (_day < d._day));
}

bool Date::operator<=(const Date &d)
{
    return (*this == d) || (*this < d);
}

Date& Date::operator++()
{
    if (_day > Day_Of_Month(_year,_month))
    {
        _day -= Day_Of_Month(_year,_month);
        _month++;
        if (_month > 12)
        {
            _year++;
            _month = 1;
        }
    }
    return *this;
}

Date Date::operator++(int)
{
    Date ret = *this;
    _day++;
    if (_day > Day_Of_Month(_year,_month))
    {
        _day = Day_Of_Month(_year,_month);
        _month++;
        if (_month > 12)
        {
            _year++;
            _month = 1;
        }
    }
    return ret;
}

Date& Date::operator--()
{
    _day--;
    if (_day < 1)
    {
        _month--;
        if (_month < 1)
        {
            _year--;
            _month = 12;
        }
        _day += Day_Of_Month(_year,_month);
    }
    return *this;
}

Date Date::operator--(int)
{
    Date ret = *this;
    _day--;
    if (_day < 1)
    {
        _month--;
        if (_month < 1)
        {
            _year--;
            _month = 12;
        }
        _day += Day_Of_Month(_year,_month);
    }
    return ret;
}

Date Date::operator+(int day)
{
    Date ret = *this;
    if (day < 0)
    {
        return ret - (-day);
    }
    ret._day += day;
    while (ret._day > Day_Of_Month(ret._year,ret._month))
    {
        ret._day -= Day_Of_Month(ret._year,ret._month);
        if (ret._month == 12)
        {
            ret._year++;
            ret._month = 1;
        } else{
            ret._month++;
        }
    }
    return ret;
}

Date& Date::operator+=(int day)
{
    *this += day;
    return *this;
}

Date Date::operator-(int day)
{
    Date ret = *this;
    if (day < 0)
    {
        return ret + (-day);
    }
    ret._day -= day;
    while (ret._day <= 0)
    {
        if (ret._month == 1)
        {
            ret._year--;
            ret._month = 12;
        }else{
            --ret._month;
        }
        ret._day += Day_Of_Month(ret._year,ret._month);
    }
    return ret;
}

Date& Date::operator-=(int day)
{
    *this -= day;
    return *this;
}

int Date::operator-(const Date &d)
{
    //比较两个日期的大小，找出最大的或者最小的
    Date Max = *this;
    Date Min = d;
    int flag = 1;
    if (*this < d)
    {
        Min = *this;
        Max = d;
        flag = -1;
    }
    int day = 0;
    while (Max != Min)
    {
        --Max;
        ++day;
    }
    return flag * day;
}

int main()
{
    Date d1(2021,12,31);
    Date d2(2021,3,1);
    cout<<d1;
    int ret = d1 - d2;
    cout<<ret<<endl;
    Date d3 = d1 + 1;
    cout<<d3<<endl;
    Date d4(d2);
    cout<<d4<<endl;
    Date d5 = d1 - 1;
    cout<<d5<<endl;
    Date d6 = d1++;
    cout<<d6<<endl;
    Date d7;
    cin>>d7;
    cout<<d7;
    d1 += 2;
    cout<<d1<<endl;
    return 0;
}