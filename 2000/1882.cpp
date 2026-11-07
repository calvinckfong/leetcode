// 1882. Process Tasks Using Servers
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int m = servers.size();
        int n = tasks.size();

        for (int i=0; i<m; i++) {
            idle.emplace(servers[i], i);
        }

        vector<int> res;
        ts = 0;
        for (int i=0; i<n; i++) {
            ts = max(ts, static_cast<long long>(i));
            release(servers);

            if (idle.empty()) {
                ts = busy.top().first;
                release(servers);
            }

            auto&& [_, idx] = idle.top();
            res.push_back(idx);
            busy.emplace(ts + tasks[i], idx);
            idle.pop();
        }
        return res;
    }

private:
    long long ts;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> idle;

    void release(vector<int>& servers) {
        while (!busy.empty() && busy.top().first<=ts) {
            auto&& [_, idx] = busy.top();
            idle.emplace(servers[idx], idx);
            busy.pop();
        }
    }
};
