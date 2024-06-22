// 1248. Count Number of Nice Subarrays
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (n<k) return 0;

        int l=0, r=0, oddCnt=0, count, result=0;
        while (l<n) {
            if (nums[l]%2) {
                oddCnt++;
                if (oddCnt>=k) {
                    count = 1;
                    while (nums[r++]%2==0) count++;
                    result +=count;
                }
            } else if (oddCnt>=k)
                result+=count;
            l++;
        }
        return result;
    }
};
