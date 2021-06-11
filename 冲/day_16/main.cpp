
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
unordered_map<char, int> helper{ {'3',1},{'4',2},{ '5',3 },{ '6',4 },{ '7',5 },{ '8',6 },
                                 { '9',7 },{ '1',8 },{ 'J',9 },{ 'Q',10 },{ 'K',11 },{ 'A',12 },{'2',13} };
string del_0(string str) {
    while (str.find('0') != string::npos)
        str.erase(str.find('0'),1);
    return str;
}
int main() {
    string str, s1, s2, s1_, s2_;
    while (getline(cin, str)) {
        s1_ = str.substr(0, str.find('-'));
        s1 = del_0(s1_);
        s2_ = str.substr(str.find('-') + 1);
        s2 = del_0(s2_);
        if (s1 == "joker JOKER" || s2 == "joker JOKER") cout << "joker JOKER" << endl;
        else if (s1.size() == 7 || s2.size() == 7) {
            if (s1.size() == 7 && s2.size() == 7)
                if (helper[s1[0]] > helper[s2[0]]) cout << s1_ << endl;
                else cout << s2_ << endl;
            else if (s1.size() == 7) cout << s1_ << endl;
            else cout << s2_ << endl;
        }
        else if (s1.size() == s2.size())
            if (helper[s1[0]] > helper[s2[0]]) cout << s1_ << endl;
            else cout << s2_ << endl;
        else cout << "ERROR" << endl;
    }
}


/*
//扑克牌大小
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<char,int> map{
        {'3',1},{'4',2},{'5',3},{'6',4},{'7',5},
        {'8',6},{'9',7},{'1',8},{'J',9},{'Q',10},
        {'K',11},{'A',12},{'2',13}
};
string del_0(string str){
    while (str.find('0') != string ::npos)
        str.erase(str.find('0'),1);
    return str;
}
int main()
{
    string str,s1,s2,s1_,s2_;
    while (getline(cin,str))
    {
        s1_ = str.substr(0,str.find('-'));
        s1 = del_0(s1_);
        s2_ = str.substr(0,str.find('-') + 1);
        s2 = del_0(s2_);
        if (s1 == "joker JOKER" || s2 == "joker JOKER")
            cout<<"joker JOKER"<<endl;
        else if (s1.size() == 7 || s2.size() == 7)
        {
            if (s1.size() == 7 && s2.size() == 7)
            {
                if (map[s1[0]] > map[s2[0]])
                    cout<<s1_<<endl;
                else
                    cout<<s2_<<endl;
            }else if (s1.size() == 7)
                cout<<s1_<<endl;
            else
                cout<<s2_<<endl;
        }
        else if (s1.size() == s2.size())
        {
            if (map[s1[0]] > map[s2[0]])
                cout<<s1_<<endl;
            else
                cout<<s2_<<endl;
        }
        else
            cout<<"ERROR"<<endl;
    }
    return 0;
}
*/


/*
//完全数
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
class Solution
{
public:
    int count(int &n)
    {
        while (cin >> n)
        {
            int count = 0;
            if (n < 0 || n > 500000)
                return -1;
            for (int i = 2;i <= n;++i)
            {
                int sum = 0;
                for (int j = 2; j <= sqrt(i); ++j)
                {
                    if (!(i % j))
                    {
                        if (i / j == j)
                            sum += j;
                    }else
                        sum += j + (i / j);
                }
                if (sum + 1 == i)
                    ++count;
            }
            return  count;
        }
        return 0;
    }
};
int main()
{
    int n = 0;
    Solution S;
    cout<<S.count(n)<<endl;
    return 0;
}
*/