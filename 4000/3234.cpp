// 3234. Count the Number of Substrings With Dominant Ones
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> pre(n+1);
        pre[0] = -1;
        pre[1] = 0;
        for (int i=1; i<n; i++) {
            if (s[i-1]=='0') {
                pre[i+1] = i;
            } else {
                pre[i+1] = pre[i];
            }
        }

        int res = 0;
        for (int i=1; i<=n; i++) {
            int cnt0 = (s[i-1] == '0');
            int j = i;
            while (j>0 && cnt0*cnt0<=n) {
                int cnt1 = (i-pre[j]) - cnt0;
                if (cnt0*cnt0 <= cnt1) {
                    res += min(j-pre[j], cnt1-cnt0*cnt0+1);
                }
                j = pre[j];
                cnt0++;
            }
        }
        return res;
    }
};
