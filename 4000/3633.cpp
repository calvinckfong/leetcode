// 3633. Earliest Finish Time for Land and Water Rides I
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int lw_time = solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int wl_time = solve(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(lw_time, wl_time);
    }

private:
    int solve(vector<int>& start1, vector<int>& duration1, vector<int>& start2, vector<int>& duration2) {
        int finish1=INT_MAX, finish2=INT_MAX;

        for (int i=0; i<start1.size(); i++) {
            finish1 = min(finish1, start1[i] + duration1[i]);
        }
        for (int i=0; i<start2.size(); i++) {
            finish2 = min(finish2, max(start2[i], finish1) + duration2[i]);
        }
        return finish2;
    }
};
