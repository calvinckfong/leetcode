// 2996. Smallest Missing Integer Greater Than Sequential Prefix Sum
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(), nums.end());
        int len = 1;

        for (int i=1; i<n; i++) {
            if (nums[i] == nums[i-1]+1)
                len++;
            else
                break;
        }

        int res = (nums[len-1] + nums[0]) * len / 2;
        while (s.count(res)) res++;

        return res;
    }
};
