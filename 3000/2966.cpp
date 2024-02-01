// 2966. Divide Array Into Arrays With Max Difference
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());

        for (int j=0; j<nums.size(); j+=3)
        {
            if (nums[j+2]-nums[j]>k) return {};

            ret.push_back({nums[j], nums[j+1], nums[j+2]});
        }

        return ret;
    }
};
