// 1298. Maximum Candies You Can Get from Boxes
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> has_box(n), used(n);

        queue<int> q;
        int result = 0;
        for (int& i: initialBoxes) {
            has_box[i] = true;
            if (status[i]==1) {
                q.push(i);
                used[i] = true;
                result += candies[i];
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int k: keys[curr]) {
                status[k] = 1;
                if (!used[k] && has_box[k]) {
                    q.push(k);
                    used[k] = true;
                    result += candies[k];
                }
            }

            for (int i: containedBoxes[curr]) {
                has_box[i] = true;
                if (!used[i] && status[i]==1) {
                    q.push(i);
                    used[i] = true;
                    result += candies[i];
                }
            }
        }

        return result;
    }
};
