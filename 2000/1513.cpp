// 1513. Number of Substrings With Only 1s
class Solution {
public:
    int numSub(string s) {
        int n = s.size(), cnt1 = 0;
        const int MOD = 1e9 + 7;
        long long res = 0;

        for (int i=0; i<n; i++) {
            if (s[i]=='1') {
                cnt1++;
            } else {
                res += (1LL + cnt1) * (cnt1) / 2LL;
                res %= MOD;
                cnt1 = 0;
            }
        }
        res += (1LL + cnt1) * (cnt1) / 2LL;
        res %= MOD;

        return res;
    }
};
