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

            if (pos<0 || pos>=n || visit[pos]) continue;

            if (arr[pos] == 0) return true;

            visit[pos] = true;

            q.push(pos + arr[pos]);
            q.push(pos - arr[pos]);
        }

        return false;
    }
};
