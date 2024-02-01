// 12. Integer to Roman
class Solution {
public:
    string lut[34] = {
        "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
        "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
        "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
        "", "M", "MM", "MMM"
    };
    string intToRoman(int num) {
        int m;
        string* p = lut;
        string ret;
        while (num>0)
        {
            m = num%10;
            ret = p[m] + ret;
            num/=10;
            p+=10;
        }
        return ret;
    }
};
