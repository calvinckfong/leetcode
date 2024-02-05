// 547. Number of Provinces
class Solution {
public:
    void dfs(int pos, vector<vector<int>>& isConnected, vector<bool>& visited)
    {
        for (int i=0; i<isConnected[pos].size(); i++)
        {
            if (isConnected[pos][i] && !visited[i])
            {
                visited[i] = true;
                dfs(i, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(), nComponent=0;
        vector<bool> visited(n, false);

        for (int i=0; i<n; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                nComponent++;
            }
            dfs(i, isConnected, visited);
        }
        return nComponent;
    }
};
