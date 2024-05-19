// 3068. Find the Maximum Sum of Node Values
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long result = accumulate(nums.begin(), nums.end(), 0LL);
        int n = nums.size();

        // It is to xor 2 nodes at a time or nothing.
        vector<long long> delta(n);
        for (int i=0; i<n; i++)
            delta[i] = (nums[i]^k) - nums[i];
        sort(delta.rbegin(), delta.rend());

        // pick the 2m nodes which increment the sum the most
        long long d, totalDelta = 0;
        for (int i=0; i<n-1; i+=2) {
            d = delta[i]+delta[i+1];
            if (d > 0LL) totalDelta += d;
            else break;
        }

        return result + totalDelta;
    }
};
