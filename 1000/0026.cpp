// 26. Remove Duplicates from Sorted Array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> tmp(nums.begin(), nums.end());

        nums = vector<int>(tmp.begin(), tmp.end());

        return nums.size();
    }
};
