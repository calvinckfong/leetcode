// 3346. Maximum Frequency of an Element After Performing Operations I
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int, int> freq, rng;
        for (int x: nums) {
            freq[x]++;

            rng[x];
            rng[x-k]++;
            rng[x+k+1]--;
        }

        int res = 0, curr = 0;
        for (auto& p: rng) {
            curr += p.second;
            res = max(res, min(curr, freq[p.first]+numOperations));
        }
        return res;
    }
};
