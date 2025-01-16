// 2425. Bitwise XOR of All Pairings
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int result = 0;
        
        if (n1&1) {
            if (n2&1) {
                for (int n: nums1) result ^= n;
                for (int n: nums2) result ^= n;
            } else {
                for (int n: nums2) result ^= n;
            }
        } else {
            if (n2&1) {
                for (int n: nums1) result ^= n;
            } else {
                result = 0;
            }
        }

        return result;
    }
};
