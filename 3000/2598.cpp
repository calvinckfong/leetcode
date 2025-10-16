// 2598. Smallest Missing Non-negative Integer After Operations
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> mp(value);
        for (int& n: nums) {
            int v = (n%value + value) % value;
            mp[v]++;
        }

        int res = 0;
        while (mp[res%value] > 0) {
            mp[res%value]--;
            res++;
        }
        return res;
    }
};
