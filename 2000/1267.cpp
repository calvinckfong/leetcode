// 1267. Count Servers that Communicate
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        const int maxN = 250;
        int m = grid.size(), n = grid[0].size();

        struct pair_hash {
            inline std::size_t operator()(const std::pair<int,int> & v) const {
                return v.first*maxN+v.second;
            }
        };
        unordered_set<pair<int, int>, pair_hash> result;

        for (int i=0; i<m; i++) {
            vector<int> onGrid;
            for (int j=0; j<n; j++) {
                if (grid[i][j]) onGrid.push_back(j);
            }
            if (onGrid.size()>1) {
                for (int j: onGrid)
                    result.insert({i,j});
            }
        }

        for (int i=0; i<n; i++) {
            vector<int> onGrid;
            for (int j=0; j<m; j++) {
                if (grid[j][i]) onGrid.push_back(j);
            }
            if (onGrid.size()>1) {
                for (int j: onGrid)
                    result.insert({j,i});
            }
        }

        return result.size();
    }
};
