// 834. Sum of Distances in Tree
class Solution {
public:
    vector<vector<int>> neighbours;
    vector<int> result; // result: sum of distances of each node
    vector<int> count; // sum of distances of this node to all its children

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // construct neighbour list for each node
        neighbours = vector<vector<int>>(n);
        for (vector<int> e: edges) {
            neighbours[e[0]].push_back(e[1]);
            neighbours[e[1]].push_back(e[0]);
        }

        result = vector<int>(n, 0);
        count = vector<int>(n, 0);
        // calculate the total number of edges for node 0 by dfs
        dfs_count(0);
        // calculation for other nodes
        dfs_sum(0, n);

        return result;
    }

private:
    void dfs_count(int curr, int parent=-1) {
        for (int i: neighbours[curr]) {
            if (i!=parent) {
                dfs_count(i, curr);
                count[curr] += count[i];
                result[curr] += result[i] + count[i];
            }
        }
        count[curr]++;
    }

    void dfs_sum(int curr, const int n, int parent=-1) {
        for (int i: neighbours[curr]) {
            if (i!=parent) {
                result[i] = result[curr] + n - 2*count[i];
                dfs_sum(i, n, curr);
            }
        }
    }
};
