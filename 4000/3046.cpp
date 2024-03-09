// 3046. Split the Array
class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int cnt[101] = {0};
        for (int i=0; i<nums.size(); i++)
        {
            cnt[nums[i]]++;
            // simply check if any values in nums contains more than twice
            if (cnt[nums[i]] > 2) return false;
        }
        return true;
    }
};
