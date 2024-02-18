// 2395. Find Subarrays With Equal Sum
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int i, sum;
        unordered_map<int, int> sums; // unordered map to count the sum occurance
        for (i=0; i<nums.size()-1; i++) {
            sum = nums[i]+nums[i+1]; 
            sums[sum]++;
            // return true when any sum occurs twice 
            if (sums[sum]>1) return true;
        }
        return false;
    }
};
