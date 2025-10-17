// 3003. Maximize the Number of Partitions After Operations
class Solution {
public:
    typedef struct {
        int num = 0;
        int mask = 0;
        int cnt = 0;
    } dp;

    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.size();
        vector<dp> l(n), r(n);
        int mask = 0, cnt = 0, num = 0;
        for (int i=0; i<n-1; i++) {
            int bin = 1 << (s[i]-'a');
            if (!(mask&bin)) {
                cnt++;
                if (cnt <= k) {
                    mask |= bin;
                } else {
                    num++;
                    mask = bin;
                    cnt = 1;
                }
            }
            l[i+1] = {num, mask, cnt};
        }

        mask = 0; cnt = 0; num = 0;
        for (int i=n-1; i>0; i--) {
            int bin = 1 << (s[i]-'a');
            if (!(mask&bin)) {
                cnt++;
                if (cnt <= k) {
                    mask |= bin;
                } else {
                    num++;
                    mask = bin;
                    cnt = 1;
                }
            }
            r[i-1] = {num, mask, cnt};
        }

        int res = 0;
        for (int i=0; i<n; i++) {
            num = l[i].num + r[i].num + 2;
            mask = l[i].mask | r[i].mask;
            cnt = 0;
            while (mask) {
                mask = mask & (mask-1);
                cnt++;
            }
            if (l[i].cnt==k && r[i].cnt==k && cnt<26) {
                num++;
            } 
            else if (min(cnt+1, 26) <= k) {
                num--;
            }
            res = max(res, num);
        }
        return res;
    }
};
