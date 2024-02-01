// 4. Median of Two Sorted Arrays
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int c = (n1+n2)/2+1;
        int p1=0, p2=0; // pointers for the 2 vectors
        int ret, prev;

        for (int i=0; i<c; i++)
        {
            if (p1<n1 && p2<n2)
            {
                if (nums1[p1] < nums2[p2])
                {
                    prev = ret;
                    ret = nums1[p1++];
                }
                else
                {
                    prev = ret;
                    ret = nums2[p2++];
                }
            }
            else if (p1<n1)
            {
                prev = ret;
                ret = nums1[p1++];
            }
            else if (p2<n2)
            {
                prev = ret;
                ret = nums2[p2++];
            }
        }

        // printf("%lf %lf\n", prev, ret);
        if ((n1+n2)%2==0)
            return 0.5*(static_cast<double>(prev+ret)); 
        return static_cast<double>(ret);
    }
};
