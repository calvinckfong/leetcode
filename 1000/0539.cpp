// 539. Minimum Time Difference
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> minutes(n);
        for (int i=0; i<n; i++) {
            minutes[i] = hhmm2minutes(timePoints[i]);
        }
        sort(minutes.begin(), minutes.end());

        int diff = minutes[n-1] - minutes[0];
        int minDiff = min(diff, 24*60-diff);
        for (int i=1; i<n; i++) {
            diff = minutes[i] - minutes[i-1];
            minDiff = min(minDiff, diff);
            minDiff = min(minDiff, 24*60 - diff);
        }
        return minDiff;
    }

private:
    int hhmm2minutes(string& s) {
        int hh = (s[0] - '0')*10 + s[1] - '0';
        int mm = (s[3] - '0')*10 + s[4] - '0';
        return hh*60 + mm; 
    }
};
