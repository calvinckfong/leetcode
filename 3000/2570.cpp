// 2570. Merge Two 2D Arrays by Summing Values
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> list;
        for (auto& val: nums1) {
            list[val[0]] = val[1];
        }
        for (auto& val: nums2) {
            list[val[0]] += val[1];
        }
        vector<vector<int>> result;
        for (auto& val: list) {
            result.push_back({val.first, val.second});
        }
        return result;
    }
};
