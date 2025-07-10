// 3440. Reschedule Meetings for Maximum Free Time II
class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<bool> q(n);
        int t1=0, t2=0;
        if (endTime[0]-startTime[0] <= t1) q[0] = true;
        t1 = max(t1, startTime[0]);
        if (endTime[n-1]-startTime[n-1] <= t2) q[n-1] = true;
        t2 = max(t2, eventTime-endTime[n-1]);
        for (int i=1; i<n; i++) {
            if (endTime[i]-startTime[i] <= t1) q[i] = true;
            t1 = max(t1, startTime[i] - endTime[i-1]);
            int j = n-i-1;
            if (endTime[j]-startTime[j] <= t2) q[j] = true;
            t2 = max(t2, startTime[j+1]-endTime[j]);
        }

        int res = 0;
        for (int i=0; i<n; i++) {
            int l = (i==0)?0:endTime[i-1];
            int r = (i==n-1)?eventTime:startTime[i+1];
            if (q[i])
                res = max(res, r-l);
            else
                res = max(res, r-l-endTime[i]+startTime[i]);
        }
        return res;
    }
};
