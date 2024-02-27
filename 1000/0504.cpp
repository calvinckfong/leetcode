// 504. Base 7
class Solution {
public:
    string convertToBase7(int num) {
        if (num==0) return "0";
        int absNum = abs(num);
        string result;
        while (absNum)
        {
            result = to_string(absNum%7) + result;
            absNum /= 7;
        }
        return (num<0)?"-"+result:result;
    }
};
