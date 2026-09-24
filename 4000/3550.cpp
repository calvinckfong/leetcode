// 3550. Smallest Index With Digit Sum Equal to Index
class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n; i++) {
            if (digitSum(nums[i]) == i) return i;
        }
        return -1;
    }

private:
    int digitSum(int x) {
        int res = 0;
        while (x>0) {
            res += (x%10);
            x /= 10;
        } 
        return res;
    }
};
