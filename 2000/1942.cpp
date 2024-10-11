// 1942. The Number of the Smallest Unoccupied Chair
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        for (int i=0; i<n; i++)
            times[i].push_back(i);
        sort(times.begin(), times.end());

        int curr_chair = 0;
        map<int, int> occupied; // chair, leaving
        for (int i=0; i<n; i++) {
            int t = times[i][0];
            int f = times[i][2];
            // clear leaved chair
            for (auto c: occupied) {
                if (c.second <= t) {
                    curr_chair = min(curr_chair, c.first);
                    occupied.erase(c.first);
                }
            }
            // return if targetFriend is found
            if (f == targetFriend) return curr_chair;
            // occupy a chair
            occupied[curr_chair] = times[i][1];
            // find next unoccupied chair
            for(int i=curr_chair+1; i<n; i++) {
                if (occupied.find(i) == occupied.end()) {
                    curr_chair = i;
                    break;
                }
            }
        }
        return 0;
    }
};
