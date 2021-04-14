//https://leetcode-cn.com/problems/valid-palindrome-ii/

//680. 验证回文字符串 Ⅱ

#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(const string &s,int left,int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
                return false;
            else
                left++,right--;
        }
        return true;
    }
public:
    bool validPalindrome(string s)
    {
        int left = 0,right = s.size() - 1;
        while (left < right)
        {
            char s1 = s[left],s2 = s[right];
            if (s1 == s2)
                left++,right--;
            else{
                return isPalindrome(s,left + 1,right) || isPalindrome(s,left,right - 1);
            }
        }
        return true;
    }
};
int main()
{
    string s = "abca";
    Solution S;
    S.validPalindrome(s);
    return 0;
}