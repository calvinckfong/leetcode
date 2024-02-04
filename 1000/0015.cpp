// 15. 3Sum
class Solution {
public:
    // Return the index m such that nums[m] == target
    // return -1 if not found
    int Find(vector<int>& nums, int start, int target)
    {
        int l=start, h=nums.size(), m;
        while (h>l)
        {
            m = l+(h-l)/2;
            if (nums[m]==target) return m;
            if (nums[m]>target)
                h = m;
            else
                l = m+1;
        }
        return -1;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int last_i = 1e6, last_j = 1e6;

        for (int i=0; i<n-2; i++)
        {
            // Prevent duplicates
            if (nums[i] == last_i) continue;

            last_i = nums[i];
            int sum = -nums[i];
            for (int j=i+1; j<n-1; j++)
            {
                // Prevent duplicates
                if (nums[j] == last_j) continue;
                
                last_j = nums[j];
                int target = sum - nums[j];

                int k = Find(nums, j+1, target);
                if (k>=0)
                    ret.push_back({nums[i], nums[j], nums[k]});
                
            }
        }
        return ret;
    }
};
