// 523. Continuous Subarray Sum
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unsigned int rem = 0;
        unordered_map<unsigned int, int> freq;
        freq[0] = -1;
        for (int i=0; i<n; i++) {
            rem = (rem+nums[i])%k;
            if (!freq.count(rem))
                freq[rem] = i;
            else if (i-freq[rem]>1) 
                return true;
        }
        return false;
    }
};
