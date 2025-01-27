// 1462. Course Schedule IV
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        for (auto edge: prerequisites) {
            adjList[edge[0]].push_back(edge[1]);
        }

        isPrerequistite = vector<vector<bool>>(numCourses, vector<bool>(numCourses));

        preprocess(numCourses, prerequisites);
    
        vector<bool> result;
        for (auto q: queries) {
            result.push_back(isPrerequistite[q[0]][q[1]]);
        }
        return result;
    }

private:
    unordered_map<int, vector<int>> adjList;
    vector<vector<bool>> isPrerequistite;

    void preprocess(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i=0; i<numCourses; i++) {
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (auto adj: adjList[curr]) {
                    if (!isPrerequistite[i][adj]) {
                        isPrerequistite[i][adj] = true;
                        q.push(adj);
                    }
                }
            }
        }
    }
};
