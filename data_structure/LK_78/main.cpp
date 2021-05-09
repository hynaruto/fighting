//76. 最小覆盖子串


#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t)
    {
        unordered_map<char,int>need,window;
        for (char c : t)
            need[c]++;
        int left = 0,right = 0,valid = 0,start = 0,len = INT8_MAX;
        while (right < s.size())
        {
            char c = s[right];
            right++;
            if (need.count(c))
            {
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }
            //判读左侧窗口是否需要收缩
            while (valid == need.size())
            {
                if (right - left < len)
                {
                    start = left;
                    len = right - left;
                }
                char d = s[left];
                left++;
                if (need.count(d))
                {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return len == INT8_MAX ? "" : s.substr(start,len);
    }
};

int main()
{
    std::string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution S;
    S.minWindow(s,t);
}