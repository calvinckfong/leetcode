// 2322. Minimum Score After Removals on a Tree
class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        sum = vector<int>(n);
        in = vector<int>(n);
        out = vector<int>(n);
        adj = vector<vector<int>>(n);
        cnt = 0;
        for (auto& e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(nums, 0, -1);

        int res = INT_MAX, s;
        for (int i=1; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (in[j]>in[i] && in[j]<out[i])
                    s = score(sum[0]^sum[i], sum[i]^sum[j], sum[j]);
                else if (in[i]>in[j] && in[i]<out[j])
                    s = score(sum[0]^sum[j], sum[i]^sum[j], sum[i]);
                else
                    s = score(sum[0]^sum[i]^sum[j], sum[i], sum[j]);

                res = min(res, s);
            }
        }
        return res;
    }

private:
    int cnt;
    vector<int> sum, in, out;
    vector<vector<int>> adj;

    void dfs(vector<int>& nums, int x, int fa) {
        in[x] = cnt++;
        sum[x] = nums[x];
        for (int& y: adj[x]) {
            if (y == fa) continue;
            dfs(nums, y, x);
            sum[x] ^= sum[y];
        }
        out[x] = cnt;
    }

    int score(int a, int b, int c) {
        return max(a, max(b, c)) - min(a, min(b, c));
    }
};
