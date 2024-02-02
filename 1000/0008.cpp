// 8. String to Integer (atoi)
class Solution {
public:
    int myAtoi(string s) {
        long ret = 0;
        int sign=1;
        bool numStart = false;

        for (int i=0; i<s.size(); i++)
        {
            if (!numStart && s[i] == ' ')
                continue;
            else if (!numStart && s[i]=='+')
            {
                numStart = true;
                continue;
            }
            else if (!numStart && s[i]=='-')
            {
                numStart = true;
                sign=-1;
            }
            else if (s[i]>='0' && s[i]<='9')
            {
                if (ret>INT_MAX)    continue;
                ret = ret*10 + s[i] - '0';
                numStart = true;
            }
            else if (numStart)
                break;
            else
                return 0;
        }
        ret = sign*ret;
        if (ret>INT_MAX)    return INT_MAX;
        else if (ret<INT_MIN)   return INT_MIN;
        else return ret;

    }
};
