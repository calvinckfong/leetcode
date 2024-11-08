// 1829. Maximum XOR for Each Query
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int maxVal = (1<<maximumBit) - 1;
        int n = nums.size(), xorSum=0;
        vector<int> result(n);
        for (int i=0; i<n; i++) {
            xorSum ^= nums[i];
            result[n-i-1] = maxVal ^ xorSum; 
        }
        return result;
    }
};
