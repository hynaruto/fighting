//https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/submissions/

//剑指 Offer 50. 第一个只出现一次的字符

#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    char firstUniqChar(string &s)
    {
        if (s.empty())
            return ' ';
        int count[26] = {0};
        for (int i = 0;i < s.size();++i)
            count[s[i] - 'a']++;
        for (int i = 0;i < s.size();++i)
        {
            if (count[s[i] - 'a'] == 1)
                return s[i];
        }
        return ' ';
    }
};
int main()
{
    Solution S;
    std::string s = "leetcode";
    S.firstUniqChar(s);
    return 0;
}