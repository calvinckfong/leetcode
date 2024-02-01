// 13. Roman to Integer
class Solution {
public:
    int romanToInt(string s) {
        int ret = 0, last=0;
        while (s.size())
        {
            if (s.back() == 'I')
            {
                ret = (last==5||last==10)?ret-1:ret+1;
                last = 1;
            }
            else if (s.back() == 'V')
            {
                ret += 5;
                last = 5;
            }
            else if (s.back() == 'X')
            {
                ret = (last==50||last==100)?ret-10:ret+10;
                last = 10;
            }
            else if (s.back() == 'L')
            {
                ret += 50;
                last = 50;
            }
            else if (s.back() == 'C')
            {
                ret = (last==500||last==1000)?ret-100:ret+100;
                last = 100;
            }
            else if (s.back() == 'D')
            {
                ret += 500;
                last = 500;
            }
            else if (s.back() == 'M')
            {
                ret += 1000;
                last = 1000;
            }
            s.pop_back();
        }
        return ret;
    }
};
