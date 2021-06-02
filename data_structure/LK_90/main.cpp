class Solution {
public:
    int myAtoi(string s)
    {
        int i = 0,flag = 1;
        while (s[i] == ' ')
            i++;
        if (s[i] == '+' || s[i] == '-')
            flag = s[i++] == '-' ? -1 : 1;
        int res = 0;
        while (s[i] >= '0' && s[i] <= '9')
        {
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && s[i] - '0' > 7))
                return flag == 1 ? INT_MAX : INT_MIN;
            res = res * 10 + (s[i++] - '0');
        }
        return flag * res;
    }
};