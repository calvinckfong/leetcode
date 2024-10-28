// 2501. Longest Square Streak in an Array
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> counts;
        int result = -1;
        for (int num: nums) {
            int sqrt_n = sqrt(num);
            if (sqrt_n*sqrt_n == num) {
                if ( counts.count(sqrt_n)>0 ) {
                    counts[num] = counts[sqrt_n]+1;
                    result = max(result, counts[num]);
                } else {
                    counts[num] = 1;
                }
            } else {
                counts[num] = 1;
            }
        }
        return result;
    }
};
