// 2864. Maximum Odd Binary Number
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size(), ones=0;
        for (int i=0; i<n; i++)
            ones += (s[i] == '1');
        return (string(ones-1, '1') + string(n-ones, '0') + "1");
    }
};
