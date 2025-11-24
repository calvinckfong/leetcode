// 1018. Binary Prefix Divisible By 5
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        int prefix=0;
        vector<bool> res(n, false);
        for (int i=0; i<n; i++) {
            prefix = prefix*2 + nums[i];
            res[i] = ((prefix%5) == 0);
            prefix %= 5;
        }
        return res;
    }
};
