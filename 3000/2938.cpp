// 2938. Separate Black and White Balls
class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        long long result = 0;
        int l=0, r=n-1;
        while (l<r) {
            while (s[l] == '0' && l<r) l++;
            while (s[r] == '1' && l<r) r--;
            result += r-l;
            s[l] = '0';
            s[r] = '1';
        }
        return result;
    }
};
