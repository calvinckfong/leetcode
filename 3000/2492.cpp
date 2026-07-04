// 2492. Minimum Score of a Path Between Two Cities
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        root = vector<int>(n+1);
        iota(root.begin(), root.end(), 0);

        for (auto& r: roads) {
            root[find(r[0])] = find(r[1]);
        }

        int res = INT_MAX;
        for (auto& r: roads) {
            if (find(r[0]) == find(1))
                res = min(res, r[2]);
        }

        return res;
    }

private:
    vector<int> root;
    int find(int i) {
        return (root[i] == i) ? i : (root[i] = find(root[i]));
    }
};
