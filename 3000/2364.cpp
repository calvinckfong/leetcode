// 2364. Count Number of Bad Pairs
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;
        unordered_map<int, int> diffCount;

        for (int i=0; i<n; i++) {
            int diff = i - nums[i];
            int good = diffCount[diff];
            result += i - good;
            diffCount[diff] = good + 1;
        }
        return result;
    }
};
