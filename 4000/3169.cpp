// 3169. Count Days Without Meetings
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        int free=0, lastEnd=0;
        for (auto& m: meetings) {
            int start = m[0];
            int end = m[1];
            if (start>lastEnd+1) {
                free += start - lastEnd - 1;
            }
            lastEnd = max(lastEnd, end);

        }
        free += days - lastEnd;
        return free;
    }
};
