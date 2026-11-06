// 2747. Count Zero Request Servers
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int nq = queries.size();
        sort(logs.begin(), logs.end(), 
            [](const auto& a, const auto& b){ return a[1]<b[1];});

        vector<int> ids(nq);
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), 
            [&](int a, int b){ return queries[a]<queries[b]; });

        vector<int> res(nq);
        vector<int> cnt(n+1);
        int l=0, r=0, active=0;
        for (int i: ids) {
            int q = queries[i];
            while (r<logs.size() && logs[r][1]<=q) {
                int id = logs[r++][0];
                if (cnt[id]++ == 0) active++;
            }
            while (l<r && logs[l][1]<q-x) {
                int id = logs[l++][0];
                if (--cnt[id] == 0) active--;
            }
            res[i] = n - active;
        }
        return res;
    }
};
