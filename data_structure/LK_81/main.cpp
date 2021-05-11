//3. 无重复字符的最长子串



#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char,int>window;
        int left = 0,right = 0;
        int res = 0;//保存结果
        while (right < s.size())
        {
            //扩大窗口
            char c = s[right];
            right++;
            window[c]++;
            //判断是否需缩小窗口
            while (window[c] > 1)
            {
                char d = s[left];
                left++;
                window[d]--;
            }
            res = max(res,right - left);
        }
        return res;
    }
};

int main()
{
    string s = "bcabcbb";
    Solution S;
    int res = S.lengthOfLongestSubstring(s);
    cout<<res<<endl;
    return 0;
}