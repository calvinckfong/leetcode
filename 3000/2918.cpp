// 2918. Minimum Equal Sum of Two Arrays After Replacing Zeros
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int zeros1=0, zeros2=0;
        long long sum1=0, sum2=0;
        for (auto& n: nums1) {
            if (n==0) {
                zeros1++;
                sum1++;
            } else {
                sum1 += n;
            }
        }
        for (auto& n: nums2) {
            if (n==0) {
                zeros2++;
                sum2++;
            } else {
                sum2 += n;
            }
        }

        if ((zeros1==0 && sum2>sum1) || 
            (zeros2==0 && sum1>sum2))
            return -1;
        return max(sum1, sum2);
    }
};
