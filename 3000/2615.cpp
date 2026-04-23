// 2615. Sum of Distances
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> groups;
        for (int i=0; i<n; i++) {
            groups[nums[i]].push_back(i);
        }

        vector<long long> res(n);
        for (const auto& p: groups) {
            const auto& g = p.second;
            long long total = accumulate(g.begin(), g.end(), 0LL);
            long long prefixSum = 0;
            for (int i=0; i<g.size(); i++) {
                res[g[i]] = total - prefixSum*2 + g[i] * (2*i - g.size());
                prefixSum += g[i];
            }
        }
        return res;
    }
};
