// 1800. Maximum Ascending Subarray Sum
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int result=0, sum=0, last=-1;

        for (auto n: nums) {
            if (n>last) {
                sum += n;
                result = max(result, sum);
            } else {
                sum = n;
            }
            last = n;
        }
        return result;
    }
};
