// 2554. Maximum Number of Integers to Choose From a Range I
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(), banned.end());
        int result = 0, sum=0, bIdx=0, bn=banned.size();
        for (int i=1; i<=n; i++) {
            if (i!=banned[bIdx]) {
                sum += i;
                if (sum<=maxSum) {
                    result++;
                } else {
                    break;
                }
            } else {
                while (bIdx<bn-1 && i==banned[bIdx]) {
                    bIdx++;
                }
            }
        }
        return result;
    }
};
