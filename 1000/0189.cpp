// 189. Rotate Array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> tmp(n);
        k = k % n;
        for (int i = 0; i < n; i++)
            tmp[i] = nums[(n - k + i) % n];
        nums = tmp;
    }
};
