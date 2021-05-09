//剑指 Offer 38. 字符串的排列

#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char,int>need,window;
        for (char c : s1)
            need[c]++;
        int left = 0,right = 0,valid = 0;
        while (right < s2.size())
        {
            //扩大窗口
            char c = s2[right];
            right++;
            if (need.count(c))
            {
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }
            //判断是否需要缩小窗口
            while (right - left > s1.size())
            {
                if (valid == need.size())
                    return true;
                char d = s2[left];
                //字符d移除窗口
                left++;
                if (need.count(d))
                {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        //没找到
        return false;
    }
};

int main()
{
    string s1 = "ab";
    string s2 = "eidboaoo";
    Solution S;
    S.checkInclusion(s1,s2);
    return 0;
}