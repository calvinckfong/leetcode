// 2040. Kth Smallest Product of Two Sorted Arrays
class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n1 = nums1.size();
        long long l=-1e10, r=1e10;
        while (l<=r) {
            long long mid = (l+r)/2;
            long long count = 0;
            for (int& n:nums1) {
                count += comb(nums2, n, mid);
            }
            if (count<k)    l = mid + 1;
            else            r = mid - 1;
        } 
        return l;
    }

private:
    int comb(vector<int>& num, long long val, long long th) {
        int n = num.size();
        int l=0, r=n-1;
        while (l<=r) {
            int mid = (l+r)/2;
            long long prod = num[mid]*val;
            if ((val>=0 && prod <= th) ||
                (val<0  && prod > th)) {
                l = mid + 1;
            } else {
                r = mid - 1;  
            }
        }
        if (val>=0) return l;
        else return n-l; 
    }
};
