// 2897. Apply Operations on Array to Maximize Sum of Squares
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        const int N = 30;
        int cnt[N] = {0};

        for (int& x: nums) {
            for (int i=0; i<N; i++) {
                if (x & (1<<i)) cnt[i]++;
            }
        }

        long long res = 0;
        for (int i=0; i<k; i++) {
            int cur = 0;
            for (int j=N-1; j>=0; j--) {
                if (cnt[j]>0) {
                    cur |= (1LL<<j);
                    cnt[j]--;
                }
            }
            res = (res + 1LL*cur*cur) % MOD;
        }
        return (int)res;
    }
};
