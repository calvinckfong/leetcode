// 1751. Maximum Number of Events That Can Be Attended II
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        len = events.size();

        dp = vector<vector<int>>(k+1, vector<int>(len, -1));
        
        return dfs(0, k, events);
    }

private:
    int len;
    vector<vector<int>> dp;
    int dfs(int curr, int count, vector<vector<int>>& events) {
        if (count==0 || curr==len)  return 0;
        if (dp[count][curr] != -1)  return dp[count][curr];

        int next = search(events, events[curr][1]);
        int val = events[curr][2] + dfs(next, count-1, events);
        val = max(val, dfs(curr+1, count, events));
        dp[count][curr] = val;
        return val;
    }

    int search(vector<vector<int>>& events, int target) {
        int l=0, r=len;
        while (l<r) {
            int mid = (l+r)/2;
            if (events[mid][0] <= target)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};
