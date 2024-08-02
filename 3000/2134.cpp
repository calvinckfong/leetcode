// 2134. Minimum Swaps to Group All 1's Together II
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int totalOne = accumulate(nums.begin(), nums.end(), 0);
        int totalZero = n - totalOne;

        int countOne = nums[0];
        int result=n, end = 0;
        for (int i=0; i<n; i++) {
            if (i>0) countOne -= nums[i-1];

            while (end-i+1 < totalOne) {
                end++;
                countOne += nums[end%n];
            }

            result = min(result, totalOne-countOne);
        }
        return result;
    }
};
