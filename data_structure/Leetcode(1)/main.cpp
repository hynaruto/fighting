bool isValid(char * s)
{
    if (*s == 0)
    {
        return true;
    }
    int len = strlen(s);
    if (len & 1)
    {
        return false;
    }
    char stack[len /2 + 1];
    for (int i = 0,top = -1;i < len && top < len>>1;++i)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            stack[++top] = s[i];
        }else if (top == -1)
        {
            return false;
        }else if (s[i] == stack[top] + 1 || s[i] == stack[top] + 2)
        {
            stack[top--] = 0;
        }else{
            return false;
        }
    }
    return !stack[0];
}