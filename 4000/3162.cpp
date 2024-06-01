// 3162. Find the Number of Good Pairs I
class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int result = 0;
        for (const int& n1: nums1) {
            for (const int& n2: nums2) {
                result += (n1 % (n2*k) == 0);
            }
        }
        return result;
    }
};
