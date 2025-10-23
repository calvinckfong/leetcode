// 3461. Check If Digits Are Equal in String After Operations I
class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        if (n == 2)
            return s[0] == s[1];

        for (int i=1; i<n; i++) {
            s[i-1] = ((s[i] + s[i-1] - 2*'0') % 10) + '0';
        }
        s.pop_back();

        return hasSameDigits(s);
    }
};
