// 3310. Remove Methods From Project
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        const int MAX_N = 1e5+2;
        vector<vector<int>> edges(n);
        vector<int> inDeg(n, 0);
        
        bitset<MAX_N> suspicious;
        suspicious.set(k);

        for (const auto& i: invocations) {
            edges[i[0]].push_back(i[1]);
            inDeg[i[1]]++;
        }

        queue<int> q;
        q.push(k);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v: edges[u]) {
                inDeg[v]--;
                if (!suspicious.test(v)) {
                    q.push(v);
                    suspicious.set(v);
                }
            }
        }

        bool removeAll = false;
        vector<int> res;

        for (int i=0; i<n; i++) {
            if (suspicious.test(i) && inDeg[i]>0) {
                removeAll = true;
                break;
            } else if (!suspicious.test(i)) {
                res.push_back(i);
            }
        }

        if (removeAll) {
            vector<int> all(n);
            iota(all.begin(), all.end(), 0);
            return all;
        }

        return res;
    }
};
