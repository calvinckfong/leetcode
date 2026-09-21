// 3524. Find X Value of Array I
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> res(k);
        vector<long long> dp(k);

        for (int i=0; i<n; i++) {
            vector<long long> tmp(k);
            tmp[nums[i]%k]++;
            for (int j=0; j<k; j++) {
                tmp[1LL * j * nums[i] % k] += dp[j];
            }

            dp = move(tmp);
            for (int j=0; j<k; j++) {
                res[j] += dp[j];
            }
        }

        return res;
    }
};
