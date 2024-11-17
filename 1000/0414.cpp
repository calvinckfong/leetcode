// 414. Third Maximum Number
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), std::greater<int>());
        int n = nums.size();
        if (n<3) {
            return nums[0];
        } else {
            int first=nums[0], second, i=1;
            while (i<n && nums[i]==first) i++;
            second = nums[i];
            while (i<n && nums[i]==second) i++;
            return (i==n)?nums[0]:nums[i];
        }
    }
};
