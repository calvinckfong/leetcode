// 2463. Minimum Total Distance Traveled
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        int rsize = robot.size(), fsize = factory.size();
        vector<vector<long long>> dp(rsize + 1, vector<long long>(fsize + 1));
        
        for (int i = 0; i < rsize; i++) {
            dp[i][fsize] = LLONG_MAX;
        }
        
        for (int j = fsize - 1; j >= 0; j--) {
            long long prefix = 0;
            deque<pair<int, long long>> q;
            q.push_back({rsize, 0});
            
            for (int i = rsize - 1; i >= 0; i--) {
                prefix += abs(robot[i] - factory[j][0]);
                
                while (!q.empty() && q.front().first > i + factory[j][1]) {
                    q.pop_front();
                }
                
                while (!q.empty() && q.back().second >= dp[i][j + 1] - prefix) {
                    q.pop_back();
                }
                
                q.push_back({i, dp[i][j + 1] - prefix});
                dp[i][j] = q.front().second + prefix;
            }
        }
        
        return dp[0][0];
    }
};
