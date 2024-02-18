// 2402. Meeting Rooms III
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<bool> inUse(n, false);
        vector<long> endTime(n, 0);
        vector<int> cnt(n, 0);
        sort(meetings.begin(), meetings.end());

        for (int i=0; i<meetings.size(); i++)
        {
            for (int j=0; j<n; j++)
            {
                // release room if meeting ended
                if (inUse[j] && endTime[j]<=meetings[i][0])
                    inUse[j] = false;
            }

            bool booked=false;
            for (int j=0; j<n; j++)
            {
                if (!inUse[j]) // book room j
                {
                    inUse[j] = true;
                    endTime[j] = meetings[i][1];
                    booked = true;
                    cnt[j]++;
                    break;
                }
            }
            if (!booked) // reschedule meeting
            {
                auto rec = min_element(endTime.begin(), endTime.end());
                int room = rec - endTime.begin();
                *rec += meetings[i][1] - meetings[i][0];
                cnt[room]++;
            }
        }

        return max_element(cnt.begin(), cnt.end()) - cnt.begin();
    }
};
