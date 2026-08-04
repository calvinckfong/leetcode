// 3731. Find Missing Elements
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> res;
        int next = nums[0] + 1;
        for (int i=1; i<n; ) {
            if (nums[i] != next) {
                res.push_back(next);
            } else {
                i++;
            }
            next++;
        }
        return res;
    }
};
