// 56. Merge Intervals
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size()<=1) return intervals;
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        // add the first interval to result
        result.push_back(intervals[0]);
        for (int i=1; i<intervals.size(); i++)
        {
            if (result.back()[1] >= intervals[i][0])
                // the last result is overlapped the coming interval
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            else
                // no overlapping
                result.push_back(intervals[i]);
        }
        return result;
    }
};
