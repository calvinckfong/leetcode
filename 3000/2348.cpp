// 2348. Number of Zero-Filled Subarrays
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0, cnt = 0;
        for (int& n: nums) {
            if (n==0) {
                cnt++;
            } else if (cnt) {
                res += (cnt+1)*cnt/2;
                cnt = 0;
            }
        }
        if (cnt) {
            res += (cnt+1)*cnt/2;
        }
        return res;
    }
};
