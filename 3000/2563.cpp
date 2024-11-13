// 2563. Count the Number of Fair Pairs
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return countPairs(nums, upper+1) - countPairs(nums, lower);
    }

private:
    long long countPairs(vector<int>& nums, int upper) {
        long long result = 0;
        int l=0, r=nums.size()-1;
        while (l<r) {
            int sum = nums[l] + nums[r];
            if (sum<upper) {
                result += (r-l);
                l++;
            } else {
                r--;
            }
        }
        return result;
    }
};
