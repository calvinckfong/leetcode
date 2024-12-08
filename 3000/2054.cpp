// 2054. Two Best Non-Overlapping Events
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
            greater<pair<int, int>>> pq;
        sort(events.begin(), events.end());

        int maxVal=0, result=0;
        for (vector<int>& e: events) {
            while (!pq.empty() && pq.top().first < e[0]) {
                maxVal = max(maxVal, pq.top().second);
                pq.pop();
            }
            result = max(result, maxVal + e[2]);
            pq.push({e[1], e[2]});
        }
        return result;
    }
};
