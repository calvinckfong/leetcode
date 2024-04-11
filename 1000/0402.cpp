// 402. Remove K Digits
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k>=num.size()) return "0";

        while (k>0 && num.size()>0)
        {
            bool erased=false;
            for (int i=0; i<num.size()-1; i++)
            {
                if (num[i]>num[i+1]) {
                    // remove digit
                    num.erase(i, 1);
                    erased = true;
                    k--;
                    // remove leading zeros
                    while (num[0] == '0') num.erase(0, 1);

                    break;
                }
            }
            if (!erased) 
            {
                while (k>0 && num.size()>0) {
                    num.pop_back(); // remove last k char
                    k--;
                }
            }
        }

        if (num.size()==0) return "0";
        else return num;
    }
};
