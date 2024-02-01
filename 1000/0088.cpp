// 88. Merge Sorted Array
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res;
        while (m || n)
        {
            if (m && n)
            {
                if (nums1.front() < nums2.front())
                {
                    res.push_back(nums1.front());
                    nums1.erase(nums1.begin());
                    m--;
                }
                else
                {
                    res.push_back(nums2.front());
                    nums2.erase(nums2.begin());
                    n--;
                }
            } 
            else if (m)
            {
                res.push_back(nums1.front());
                nums1.erase(nums1.begin());
                m--;
            }
            else if (n)
            {
                res.push_back(nums2.front());
                nums2.erase(nums2.begin());
                n--;
            }
        }

        nums1.clear();
        for (int i=0; i<res.size(); i++)
        {
            printf("%d ", res[i]);
            nums1.push_back(res[i]);
        }
    }
};
