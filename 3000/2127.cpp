// 2127. Maximum Employees to Be Invited to a Meeting
class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> inDegree(n);
        for (int i=0; i<n; i++)
            inDegree[favorite[i]]++;

        queue<int> q;
        for (int i=0; i<n; i++) {
            if (inDegree[i]==0) q.push(i);
        }

        vector<int> depth(n, 1);
        while (!q.empty()) {
            int currNode = q.front();
            q.pop();
            int nextNode = favorite[currNode];
            depth[nextNode] = max(depth[nextNode], depth[currNode]+1);
            if (--inDegree[nextNode]==0) q.push(nextNode);
        }

        int maxLen = 0, twoCycle=0;
        for (int i=0; i<n; i++) {
            if (inDegree[i]==0) continue;

            int currLen = 0;
            int curr = i;
            while (inDegree[curr]) {
                inDegree[curr] = 0;
                currLen++;
                curr = favorite[curr];
            }

            if (currLen == 2) {
                twoCycle += depth[i] + depth[favorite[i]];
            } else {
                maxLen = max(maxLen, currLen);
            }
        }

        return max(maxLen, twoCycle);
    }
};
