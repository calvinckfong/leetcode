// 2033. Minimum Operations to Make a Uni-Value Grid
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        int len = m*n;
        vector<int> nums(len);

        int rem = grid[0][0] % x, idx=0;
        for (int i=0; i<m; i++) {
            for (auto num: grid[i]) {
                if (num%x != rem) return -1;
                nums[idx++] = num; 
            }
        }

        sort(nums.begin(), nums.end());

        int l=0, r=len-1, result=0, op;
        while (l<r) {
            if (l < len-r-1) {
                op = (l+1) * (nums[l+1] - nums[l]) / x;
                l++;
            } else {
                op = (len-r) * (nums[r] - nums[r-1]) / x;
                r--;
            }
            result += op;
        }
        
        return result;
    }
};
