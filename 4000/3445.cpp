// 3445. Maximum Difference Between Even and Odd Frequency II

#define status(a,b) ((((a)&1)<<1)|((b)&1))

class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size();
        int res = INT_MIN;
        for (char i='0'; i<'5'; i++) {
            for (char j='0'; j<'5'; j++) {
                if (i==j) continue;

                int best[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
                int cnt_i=0, cnt_j=0;
                int prev_i=0, prev_j=0;
                for (int r=0, l=-1; r<n; r++) {
                    cnt_i += (s[r]==i);
                    cnt_j += (s[r]==j);
                    while (r-l>=k && cnt_j-prev_j>=2) {
                        int l_status = status(prev_i, prev_j);
                        best[l_status] =
                            min(best[l_status], prev_i-prev_j);
                        l++;
                        prev_i += (s[l]==i);
                        prev_j += (s[l]==j);
                    }

                    int r_status = status(cnt_i, cnt_j);
                    if (best[r_status^2] != INT_MAX) {
                        res = max(res, cnt_i-cnt_j-best[r_status^2]);
                    }
                }
            }
        }
        return res;
    }
};
