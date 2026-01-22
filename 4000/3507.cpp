// 3507. Minimum Pair Removal to Sort Array I
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n);
        iota(next.begin(), next.end(), 1);
        next[n-1] = -1;

        int res = 0;
        while (res < n-1) {
            int cur = 0;
            int tar = 0;
            int tarSum = nums[tar] + nums[next[tar]];
            bool valid = true;
            while (cur!=-1 && next[cur]!=-1) {
                if (nums[cur] > nums[next[cur]]) {
                    valid = false;
                }

                int curSum = nums[cur] + nums[next[cur]];
                if (curSum < tarSum) {
                    tar = cur;
                    tarSum = curSum;
                }
                cur = next[cur];
            }

            if (valid) break;

            res++;
            next[tar] = next[next[tar]];
            nums[tar] = tarSum;
        }

        return res;
    }
};
