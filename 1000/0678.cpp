// 678. Valid Parenthesis String
class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int l1=0, r1=0, s1=0;
        int l2=0, r2=0, s2=0;
        for (int i=0; i<n; i++) {
            // forward checking
            if (s[i] == '(') l1++;
            else if (s[i] == ')') r1++;
            else if (s[i] == '*') s1++;
            if (l1+s1<r1) return false;

            // reverse checking
            int j=n-i-1;
            if (s[j] == '(') l2++;
            else if (s[j] == ')') r2++;
            else if (s[j] == '*') s2++;
            if (r2+s2<l2) return false;
        }
        return true;
    }
};
