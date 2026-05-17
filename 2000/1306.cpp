// 1306. Jump Game III
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visit(n, false);
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int pos = q.front();
            q.pop();

            if (arr[pos] == 0) return true;

            visit[pos] = true;

            int next;
            next = pos + arr[pos];
            if (next<n && !visit[next]) q.push(next);
            next = pos - arr[pos];
            if (next>=0 && !visit[next]) q.push(next);
        }

        return false;
    }
};
