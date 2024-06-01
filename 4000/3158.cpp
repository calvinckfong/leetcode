// 3158. Find the XOR of Numbers Which Appear Twice
class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int result=0, freq[51]={0};
        sort(nums.begin(), nums.end());
        for (const int& n: nums) {
            if (freq[n]) result ^= n;
            freq[n]++;
        }
        return result;
    }
};
