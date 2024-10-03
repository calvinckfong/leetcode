// 1590. Make Sum Divisible by P
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int totalRem = 0;

        for (int i=0; i<n; i++)
            totalRem = (totalRem + nums[i]) % p;

        int target = totalRem % p;
        if (target == 0) return 0;

        unordered_map<int, int> modMap;
        modMap[0] = -1;

        int currentSum=0, minLen=n;
        for (int i=0; i<n; i++) {
            currentSum = (currentSum + nums[i]) % p;

            int needed = (currentSum - target + p) % p;

            if (modMap.find(needed) != modMap.end()) {
                minLen = min(minLen, i-modMap[needed]);
            }

            modMap[currentSum] = i;
        }

        return (minLen==n) ? -1 : minLen;
    }
};
