//https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&tqId=11181&rp=1&ru=%2Factivity%2Foj&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tab=answerKey


//数组中出现次数超过一半的数字
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if (numbers.size()==0)
            return 0;
        int morgen = 0,vote = 0;
        for (int i = 0;i < numbers.size();++i)
        {
            if (vote == 0)
            {
                morgen = numbers[i];
                vote++;
            }else{
                if (numbers[i] == morgen)
                {
                    vote++;
                }else{
                    vote--;
                }
            }
        }
        int tmp = 0;
        for (int i = 0;i < numbers.size();++i)
        {
            if (numbers[i] == morgen)
                tmp++;
            if (tmp > numbers.size() / 2)
                return morgen;
        }
        return 0;
    }
};
int main()
{
    Solution S;
    S.MoreThanHalfNum_Solution({1,2,3,2,2,2,5,4,2});
    return 0;
}