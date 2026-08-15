// 3702. Longest Subsequence With Non-Zero Bitwise XOR
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int sum=0, allzero = 1;

        for (int&x: nums) {
            sum ^= x;
            if (x) allzero = 0;
        }

        if (sum) return n;
        return (allzero)?0:n-1;
    }
};
