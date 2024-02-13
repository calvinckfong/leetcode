// 228. Summary Ranges
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size()==0) return {};

        vector<string> result;
        int start = nums[0], n=nums.size();
        for (int i=1; i<n; i++)
        {
            if (nums[i]==nums[i-1]+1)
                continue;
            else if (start == nums[i-1])
            {
                result.push_back(to_string(start));
            }
            else
            {
                result.push_back(to_string(start)+"->"+to_string(nums[i-1]));
            }
            start = nums[i];
        }
        if (start==nums[n-1])
            result.push_back(to_string(start));
        else
            result.push_back(to_string(start)+"->"+to_string(nums[n-1]));
        return result;
        
    }
};
