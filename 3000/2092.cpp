// 2092. Find All People With Secret
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), [](auto& a, auto& b){
            return a[2] < b[2];
        });
        
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto& m: meetings) {
            int x = m[0], y = m[1], t = m[2];
            graph[x].emplace_back(t, y);
            graph[y].emplace_back(t, x);
        }

        vector<int> earliest(n, INT_MAX);
        earliest[0] = 0;
        earliest[firstPerson] = 0;

        queue<pair<int, int>> q;
        q.emplace(0, 0);
        q.emplace(firstPerson, 0);
        while (!q.empty()) {
            auto [curr, time] = q.front();
            q.pop();
            for (auto [t, next]: graph[curr]) {
                if (t>=time && earliest[next]>t) {
                    earliest[next] = t;
                    q.emplace(next, t);
                }
            }
        }

        vector<int> res;
        for (int i=0; i<n; i++) {
            if (earliest[i] != INT_MAX) {
                res.push_back(i);
            }
        }
        return res;
    }
};
