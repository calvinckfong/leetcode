// 452. Minimum Number of Arrows to Burst Balloons
class Solution {
public:
    bool isOverlap(vector<int> a, vector<int> b)
    {
        int l = max(a[0], b[0]);
        int r = min(a[1], b[1]);
        return (l<=r);
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int currMax = points[0][1];
        int cnt = 1;
        for (int i=1; i<points.size(); i++)
        {
            if (points[i][0]>currMax) // no more overlapping
            {
                currMax = points[i][1];
                cnt++;
            }
            // shrink the upper bound if needed
            currMax = min(currMax, points[i][1]);
        }
        
        return cnt;
    }
};
