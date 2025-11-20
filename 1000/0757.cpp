// 757. Set Intersection Size At Least Two
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), 
            [](vector<int>& a, vector<int>& b){
                return (a[1]==b[1])?(a[0]>b[0]):(a[1]<b[1]);
            });

        int n=intervals.size(), res = 2;
        int b=intervals[0][1], a=b-1;
        for (int i=1;i <n; i++) {
            const int l=intervals[i][0], r=intervals[i][1];
            if (a>=l) continue;
            if (l>b) {
                res += 2;
                a = r-1;
                b = r;
            } else {
                res++;
                a = b;
                b = r;
            }
        }
        return res;
    }
};
