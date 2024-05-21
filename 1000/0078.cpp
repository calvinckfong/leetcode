// 78. Subsets
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size()==0) return result;

        result.push_back({});
        result.push_back({nums[0]});
        for (int i=1; i<nums.size(); i++) {
            int n = result.size();
            for (int j=0; j<n; j++) {
                vector<int> tmp = result[j];
                tmp.push_back(nums[i]);
                result.push_back(tmp);
            }
        }
        return result;
    }
};
