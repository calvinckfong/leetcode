// 1404. Number of Steps to Reduce a Number in Binary Representation to One
class Solution {
public:
    int numSteps(string s) {
        int result = 0;
        while (s.size()>1) {
            char c = s.back();
            s.pop_back();
            int carry = (c == '1');
            if (carry) {
                int i = s.size()-1;
                s += "0";
                while (carry && i>=0) {
                    if (s[i] == '1') {
                        s[i] = '0';
                    } else {
                        s[i] = '1';
                        carry = 0;
                    }
                    i--;
                }
            }
            if (carry) s = "1" + s;
            result ++;
        }
        return result;
    }
};
