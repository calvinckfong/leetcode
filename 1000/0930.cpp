// 930. Binary Subarrays With Sum
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int l=0, r=1, n=nums.size();
        int sum = 0, result = 0;
        
        for (int l=0; l<n; l++)
        {
            sum = 0;
            for (int r=l; r<n; r++)
            {
                sum += nums[r];
                if (sum==goal) result++;
                else if (sum>goal) {
                    break;
                }
            }
        }
        return result;
    }
};
