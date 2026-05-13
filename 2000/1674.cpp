// 1674. Minimum Moves to Make Array Complementary
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2*limit+2, 0);

        int a, b;
        for (int i=0; i<n/2; i++) {
            a = min(nums[i], nums[n-1-i]);
            b = max(nums[i], nums[n-1-i]);

            diff[2] += 2;
            diff[a+1]--;
            diff[a+b]--;
            diff[a+b+1]++;
            diff[b+limit+1]++;
        }

        int res = n, curr=0;
        for (int i=2; i<=2*limit; i++) {
            curr += diff[i];
            res = min(res, curr);
        }

        return res;
    }
};
