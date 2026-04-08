// 3653. XOR After Range Multiplication Queries I
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        for (auto& q: queries) {
            int l=q[0], r=q[1], k=q[2], v=q[3];
            for (int i=l; i<=r; i+=k) {
                nums[i] = ((long long)nums[i] * v) % MOD;
            }
        }

        int res = 0;
        for (auto& x: nums) {
            res ^= x;
        }
        return res;
    }
};
