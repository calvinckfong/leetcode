// 2106. Maximum Fruits Harvested After at Most K Steps
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> sum(n+1);
        vector<int> idx(n);
        for (int i=0; i<n; i++) {
            idx[i] = fruits[i][0];
            sum[i+1] = sum[i] + fruits[i][1];
        }

        int res = 0;
        int l, r, start, end;
        for (int i=0, j=k; i<=k/2; i++, j-=2) {
            l = startPos - i;
            r = startPos + j;
            start = lower_bound(idx.begin(), idx.end(), l) - idx.begin();
            end = upper_bound(idx.begin(), idx.end(), r) - idx.begin();
            res = max(res, sum[end] - sum[start]);

            l = startPos - j;
            r = startPos + i;
            start = lower_bound(idx.begin(), idx.end(), l) - idx.begin();
            end = upper_bound(idx.begin(), idx.end(), r) - idx.begin();
            res = max(res, sum[end] - sum[start]);
        }
        return res;
    }
};
