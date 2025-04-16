// 2537. Count the Number of Good Subarrays
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int same = 0, r = -1;
        unordered_map<int, int> cnt;
        long long result = 0;
        for (int l=0; l<n; l++) {
            while (same<k && r+1<n) {
                r++;
                same += cnt[nums[r]];
                cnt[nums[r]]++;
            }
            if (same>=k)
                result += n - r;
            cnt[nums[l]]--;
            same -= cnt[nums[l]];
        }
        return result;
    }
};
