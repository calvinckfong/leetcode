// 3876. Construct Uniform Parity Array II
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1[0];
        bool hasOdd = false;
        for (int& x: nums1) {
            if (x<n) n = x;
            if (x&1) hasOdd = true;
        }
        if (n&1) return true;
        return !hasOdd;
    }
};
