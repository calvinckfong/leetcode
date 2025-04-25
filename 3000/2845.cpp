// 2845. Count of Interesting Subarrays
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int prefix = 0;
        long long result = 0;
        for (int i=0; i<n; i++) {
            prefix += ((nums[i] % modulo) == k);
            result += cnt[(prefix-k+modulo) % modulo];
            cnt[prefix%modulo]++;
        }
        return result;
    }
};
