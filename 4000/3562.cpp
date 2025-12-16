// 3562. Maximum Profit from Trading Stocks with Discounts
class Solution {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        g = vector<vector<int>>(n);
        for (auto& h: hierarchy) {
            g[h[0]-1].push_back(h[1]-1);
        }
        return std::get<0>(dfs(0, present, future, budget))[budget];
    }

private:
    vector<vector<int>> g;

    tuple<vector<int>, vector<int>, int> dfs (int idx, vector<int>& present, vector<int>& future, int budget) {
        int cost = present[idx];
        int dCost = cost / 2;

        auto dp0 = vector(budget+1, 0);
        auto dp1 = vector(budget+1, 0);
        auto subP0 = vector(budget+1, 0);
        auto subP1 = vector(budget+1, 0);

        int uSize = cost;

        for (auto node: g[idx]) {
            auto [subDp0, subDp1, vSize] = dfs(node, present, future, budget);
            uSize += vSize;
            for (int i=budget; i>=0; i--) {
                for (int j=0; j<=min(vSize,i); j++) {
                    subP0[i] = max(subP0[i], subP0[i-j] + subDp0[j]);
                    subP1[i] = max(subP1[i], subP1[i-j] + subDp1[j]);
                }
            }
        }

        for (int i=0; i<=budget; i++) {
            dp0[i] = dp1[i] = subP0[i];
            if (i>=dCost) {
                dp1[i] = max(subP0[i], subP1[i-dCost] + future[idx] - dCost);
            }
            if (i>=cost) {
                dp0[i] = max(subP0[i], subP1[i-cost] + future[idx] - cost);
            }
        }

        return {dp0, dp1, uSize};
    };
};
