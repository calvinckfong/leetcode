// 1752. Check if Array Is Sorted and Rotated
class Solution {
public:
    bool check(vector<int>& nums) {
        const int n = nums.size();
        int cnt = 0;
        for (int i=0; i<n-1; i++) {
            cnt += (nums[i+1]<nums[i]);
        }
        cnt += (nums[0]<nums[n-1]);
        return cnt<2;
    }
};
