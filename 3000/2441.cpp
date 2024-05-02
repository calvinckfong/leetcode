// 2441. Largest Positive Integer That Exists With Its Negative
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int result = -1;
        unordered_map<int, int> mp;
        for (int n: nums) {
            if (n>0) {
                mp[n] |= 2;
            } else {
                mp[-n] |= 1;
            }
            if (mp[abs(n)]==3) result = max(result, abs(n));
        }
        return result;
    }
};
