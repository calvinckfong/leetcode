// 1701. Average Waiting Time
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double result = 0.0;
        int endTime = 0;
        for (int i=0; i<n; i++) {
            if (endTime <= customers[i][0]) {
                // customer arrives later than last session end time
                result += customers[i][1];
                endTime = customers[i][0] + customers[i][1];
            } else {
                // customer arrives before last session end time
                endTime += customers[i][1];
                result += (endTime - customers[i][0]);
            }
        }
        return result / n;
    }
};
