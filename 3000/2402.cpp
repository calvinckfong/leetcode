// 2402. Meeting Rooms III
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        sort(meetings.begin(), meetings.end());
        vector<long> endTime(n, 0);
        vector<int> cnt(n, 0);
        priority_queue<int, vector<int>, greater<>> aval;
        for (int i=0; i<n; i++)
            aval.push(i);

        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<>> busy;

        for (vector<int>& m: meetings) {
            long start = m[0], end = m[1];

            while (!busy.empty() && busy.top().first<=start) {
                aval.push(busy.top().second);
                busy.pop();
            }

            if (!aval.empty()) {
                int rm = aval.top();
                aval.pop();
                endTime[rm] = end;
                cnt[rm]++;
                busy.push({end, rm});
            } else {
                auto [et, rm] = busy.top();
                busy.pop();
                endTime[rm] = et + (end-start);
                cnt[rm]++;
                busy.push({endTime[rm], rm});
            }
        }

        int res = 0;
        for (int i=1; i<n; i++) {
            if (cnt[i]>cnt[res]) res = i;
        }
        return res;
    }
};
