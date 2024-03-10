// 1577. Number of Ways Where Square of Number Is Equal to Product of Two Numbers
class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;
        unordered_map<long, int> cnt1, cnt2;
        for (long n: nums1) cnt1[n*n]++;
        for (long n: nums2) cnt2[n*n]++;

        for (int j=0; j<nums2.size(); j++)
            for (int k=j+1; k<nums2.size(); k++)
                result += cnt1[long(nums2[j])*long(nums2[k])];
        
        for (int j=0; j<nums1.size(); j++)
            for (int k=j+1; k<nums1.size(); k++)
                result += cnt2[long(nums1[j])*long(nums1[k])];

        return result;
    }
};
