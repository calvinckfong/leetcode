// 1353. Maximum Number of Events That Can Be Attended
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        int maxday = 0;
        for (auto& e: events)
            maxday = max(maxday, e[1]);
        
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<>> pq;
        int res = 0;
        for (int i=0, j=0; i<=maxday; i++) {
            while (j<n && events[j][0]<=i) {
                pq.push(events[j++][1]);
            }

            while (!pq.empty() && pq.top()<i) {
                pq.pop();
            }

            if (!pq.empty()) {
                pq.pop();
                res++;
            }
        }

        return res;
    }
};
