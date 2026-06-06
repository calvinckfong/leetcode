// 2574. Left and Right Sum Differences
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);

        int sum = 0;
        for (int i=1; i<n; i++) {
            sum += nums[i-1];
            res[i] = sum;
        }

        sum = 0;
        for (int i=n-2; i>=0; i--) {
            sum += nums[i+1];
            res[i] = abs(res[i] - sum);
        }

        return res;
    }
};
