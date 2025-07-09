// 3439. Reschedule Meetings for Maximum Free Time I
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        int res = 0;
        vector<int> sum(n+1);

        for (int i=0; i<n; i++) {
            sum[i+1] = sum[i] + endTime[i] - startTime[i];
        }

        for (int i=k-1; i<n; i++) {
            int r = (i==n-1) ? eventTime : startTime[i+1];
            int l = (i==k-1) ? 0 : endTime[i-k];
            res = max(res, r-l-sum[i+1]+sum[i-k+1]);
        }
        return res;
    }
};
