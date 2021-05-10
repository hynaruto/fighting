//438. 找到字符串中所有字母异位词

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        unordered_map<char,int>need,window;
        vector<int>res;
        int left = 0,right = 0,valid = 0;
        for (char c : p)
            need[c]++;
        while (right < s.size())
        {
            //扩大窗口
            char c = s[right];
            right++;
            if (need.count(c))
            {
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }
            while (right - left >= p.size())
            {
                //缩小窗口，并收集结果
                if (valid == need.size())
                    res.push_back(left);
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
        return res;
    }
};
int main()
{
    string s = "cbaebabacd";
    string p = "abc";
    Solution S;
    vector<int>res;
    res = S.findAnagrams(s,p);
    for (int i = 0;i < res.size();++i)
        cout<<res[i]<<endl;
    return 0;
}