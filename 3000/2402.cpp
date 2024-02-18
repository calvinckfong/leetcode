// 2402. Meeting Rooms III
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int i, j, room;
        int start, end;
        bool booked;
        vector<long>::iterator rec;
        sort(meetings.begin(), meetings.end());
        vector<long> endTime(n, 0);
        vector<int> cnt(n, 0);

        for (i=0; i<meetings.size(); i++)
        {
            start = meetings[i][0];
            end = meetings[i][1];
            booked=false;
            for (j=0; j<n; j++)
            {
                if (endTime[j]<=start)
                {
                    // book room j
                    endTime[j] = end;
                    booked = true;
                    cnt[j]++;
                    break;
                }
            }
            if (!booked) // reschedule meeting
            {
                rec = min_element(endTime.begin(), endTime.end());
                room = rec - endTime.begin();
                *rec += end-start;
                cnt[room]++;
            }
        }

        return max_element(cnt.begin(), cnt.end()) - cnt.begin();
    }
};
