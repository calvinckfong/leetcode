// 696. Count Binary Substrings
class Solution {
public:
    int countBinarySubstrings(string s) {
        int ones=0, n=s.size();
        int prev=0, curr=1, res = 0;

        for (int i=1; i<n; i++) {
            if (s[i-1]!=s[i]) {
                res += min(prev, curr);
                prev = curr;
                curr = 1;
            } else {
                curr++;
            }
        }
        return res + min(prev, curr);
    }
};
