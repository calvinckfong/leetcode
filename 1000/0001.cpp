// 1. Two Sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size(), diff, i;
        unordered_map<int, int> map;
        for (i=0; i<n; i++)
        {
            diff = target - nums[i];
            if (map.count(diff))
                return {map[diff], i};
            map[nums[i]] = i;
        }
        return {};
    }
};
