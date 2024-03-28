// 2958. Length of Longest Subarray With at Most K 
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0, r=0, n=nums.size();
        int curr, result=0;
        unordered_map<int, int> freq;

        for (; r<n; r++)
        {
            curr = nums[r];
            freq[curr]++;

            // check if curr freq is greater than k
            if (freq[curr]>k) {
                // remove by l move until nums[l] equals to curr
                do {
                    freq[nums[l++]]--;
                } while (nums[l-1]!=curr);
            }
            else 
                result = max(result, r-l+1);
        }
        return result;
    }
};
