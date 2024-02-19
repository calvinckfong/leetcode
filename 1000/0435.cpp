// 435. Non-overlapping Intervals
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort by end point
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[1]<b[1];
        });
        int cnt=0, currPos = intervals[0][1];
        for (int i=1; i<intervals.size(); i++)
        {
            if (currPos>intervals[i][0])    // if overlapped
                cnt++;
            else
                currPos = intervals[i][1];  // move to next end point
        }
        return cnt;
    }
};
