// 3551. Minimum Swaps to Sort by Digit Sum
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> dSum(n);
        for (int i=0; i<n; i++) {
            dSum[i] = digitSum(nums[i]);
        }

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){
            if (dSum[a] != dSum[b]) {
                return dSum[a] < dSum[b];
            }
            return nums[a] < nums[b];
        });

        vector<int> pos(n);
        for (int i=0; i<n; i++) {
            pos[idx[i]] = i;
        }

        vector<int> vis(n);
        int res = n;
        for (int i=0; i<n; i++) {
            if (!vis[i]) {
                res--;
                int j = i;
                while (!vis[j]) {
                    vis[j] = true;
                    j = pos[j];
                }
            }
        }
        return res;
    }

private:
    int digitSum(int x) {
        int res = 0;
        while (x>0) {
            res += x % 10;
            x /= 10;
        }
        return res;
    }
};
