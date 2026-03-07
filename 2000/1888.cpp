// 1888. Minimum Number of Flips to Make the Binary String Alternating
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        vector<int> pre0(n), pre1(n);
        pre0[0] = valid(s[0], 1);
        pre1[0] = valid(s[0], 0);
        for (int i = 1; i < n; ++i) {
            pre0[i] = pre1[i - 1] + valid(s[i], 1);
            pre1[i] = pre0[i - 1] + valid(s[i], 0);
        }

        int res = min(pre0[n - 1], pre1[n - 1]);
        if (n%2) {
            vector<int> suf0(n), suf1(n);
            suf0[n-1] = valid(s[n-1], 1);
            suf1[n-1] = valid(s[n-1], 0);
            for (int i = n - 2; i >= 0; --i) {
                suf0[i] = suf1[i + 1] + valid(s[i], 1);
                suf1[i] = suf0[i + 1] + valid(s[i], 0);
            }
            for (int i = 0; i<n-1; ++i) {
                res = min(res, pre0[i] + suf0[i+1]);
                res = min(res, pre1[i] + suf1[i+1]);
            }
        }

        return res;
    }
private:
    int valid(char c, int x) { return c=='0'+x; }
};
