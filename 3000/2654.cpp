// 2654. Minimum Number of Operations to Make All Array Elements Equal to 1
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, g = 0;

        for (int x:nums) {
            cnt1 += (x==1);
            g = gcd(g, x);
        }
        if (cnt1>0) return n - cnt1;
        if (g>1) return -1;

        int min_len = n;
        for (int i=0; i<n; i++) {
            g = 0;
            for (int j=i; j<n; j++) {
                g = gcd(g, nums[j]);
                if (g==1) {
                    min_len = min(min_len, j-i+1);
                    break;
                }
            }
        }
        return min_len + n - 2;
    }
};
