// 992. Subarrays with K Different Integers
class Solution {
public:
    int subarrayWithAtMostK(vector<int>& nums, int k) {
        int result=0, curr, l, r, n=nums.size();
        unordered_map<int, int> freq;
        for (l=0, r=0; r<n; r++)
        {
            freq[nums[r]]++;

            while (freq.size()>k) {
                curr = nums[l];
                freq[curr]--;
                if (freq[curr]==0)
                    freq.erase(curr);
                l++;
            }  

            result += (r-l+1);
        }
        return result;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrayWithAtMostK(nums, k) - subarrayWithAtMostK(nums, k-1);
    }
};
