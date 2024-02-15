// 2971. Find Polygon With the Largest Perimeter
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long perimeter = accumulate(nums.begin(), nums.end()-1, 0LL);
        int p = nums.size()-1;
        int longest = nums[p];
        while (perimeter<=longest && p>=2)
        {
            p--;
            longest = nums[p];
            perimeter-=longest;
        }
        if (p<2) return -1;
        return perimeter+longest;
    }
};
