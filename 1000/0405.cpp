// 405. Convert a Number to Hexadecimal
class Solution {
public:
    string toHex(int num) {
        string hexchar = "0123456789abcdef";
        string result;
        unsigned int tmp = num;
        do
        {
            result = hexchar[tmp%16] + result;
            tmp /= 16; 
        } while (tmp);
        return result;
    }
};
