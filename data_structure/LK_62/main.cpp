



//https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/submissions/

//剑指 Offer 31. 栈的压入、弹出序列


#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0;
        for (int num : pushed)
        {
            s.push(num);
            while (!s.empty() && s.top() == popped[i])
            {
                s.pop();
                ++i;
            }
        }

        return s.empty();
    }
};