// 2406. Divide Intervals Into Minimum Number of Groups
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        map<int, int> count;
        for (int i=0; i<n; i++) {
            count[intervals[i][0]]++;
            count[intervals[i][1]+1]--;
        }

        int concurrent=0, result = 0;
        for (pair<int, int> p: count) {
            concurrent += p.second;
            result = max(result, concurrent);
        }
        return result;
    }
};
