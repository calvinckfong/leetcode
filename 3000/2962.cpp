// 2962. Count Subarrays Where Max Element Appears at Least K Times
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement = *max_element(nums.begin(), nums.end());        
        int l, r, cnt=0, n=nums.size();
        long long result = 0;
        for (l=0, r=0; r<n; r++)
        {
            cnt += (nums[r]==maxElement);
            while (cnt >= k) {
                cnt -= (nums[l++]==maxElement);
            }
            result += l;
        }

        return result;
    }
};
