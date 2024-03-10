// 349. Intersection of Two Arrays
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1(nums1.begin(), nums1.end());
        unordered_set<int> n2(nums2.begin(), nums2.end());
        vector<int> result;
        for (int p1: n1)
        {
            for (int p2: num2)
            {
                if (p1 == p2)
                    result.push_back(p1);
            }
        }
        return result;
    }
};
