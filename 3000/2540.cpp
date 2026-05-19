// 2540. Minimum Common Value
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i1=0, i2=0;
        int res = 1e9;

        while (i1<nums1.size() && i2<nums2.size()) {
            int x1 = nums1[i1];
            int x2 = nums2[i2];
            
            if (x1 == x2) return x1;
            else if (x1 > x2) i2++;
            else i1++;
        }

        return -1;
    }
};
