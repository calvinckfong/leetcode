// 1569. Number of Ways to Reorder Array to Get Same BST
class Solution {
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        table.resize(n+1);
        for (int i=0; i<n+1; i++) {
            table[i] = vector<long long>(i+1, 1);
            for (int j=1; j<i; j++) {
                table[i][j] = (table[i-1][j-1] + table[i-1][j]) % MOD;
            }
        }
        return (dfs(nums)-1) % MOD;
    }

private:
    const int MOD = 1e9 + 7;
    vector<vector<long long>> table;

    long long dfs(vector<int> &nums) {
        int n = nums.size();
        if (n<3) return 1;

        vector<int> lnodes, rnodes;
        for (int i=1; i<n; i++) {
            if (nums[i]<nums[0])
                lnodes.push_back(nums[i]);
            else
                rnodes.push_back(nums[i]);
        }

        long long lcnt = dfs(lnodes) % MOD;
        long long rcnt = dfs(rnodes) % MOD;

        return (((lcnt*rcnt)%MOD) * table[n-1][lnodes.size()]) % MOD;
    }
};
