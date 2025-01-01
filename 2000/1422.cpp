// 1422. Maximum Score After Splitting a String
class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int zeros = 0;
        for (int i=0; i<n; i++)
            zeros += (s[i]=='0');

        int result = 0, l=0, r=n-zeros;
        for (int i=0; i<n-1; i++) {
            if (s[i]=='0') {
                l++;
            } else {
                r--;
            }
            result = max(result, l+r);
        }
        return result;
    }
};
