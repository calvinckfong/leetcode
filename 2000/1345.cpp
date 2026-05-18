// 1345. Jump Game IV
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n==1) return 0;

        unordered_map<int, vector<int>> mp;
        for (int i=0; i<n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<pair<int, int>> q;
        vector<bool> visit(n, false);
        q.push({0, 0});
        visit[0] = true;

        while (!q.empty()) {
            int idx = q.front().first;
            int dis = q.front().second;
            q.pop();

            if (idx==n-1) return dis;
            
            int next = idx-1;
            if (next>=0 && !visit[next]) {
                visit[next] = true;
                q.push({next, dis+1});
            }

            next = idx+1;
            if (next<n && !visit[next]) {
                visit[next] = true;
                q.push({next, dis+1});
            }

            for (int& i: mp[arr[idx]]) {
                if (!visit[i]) {
                    visit[i] = true;
                    q.push({i, dis+1});
                }
            }

            mp[arr[idx]].clear();
        }
        return -1;
    }
};
