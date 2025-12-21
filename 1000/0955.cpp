// 955. Delete Columns to Make Sorted II
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<bool> sorted(n-1, false);

        int res = 0;
        for (int i=0; i<m; i++) {
            bool valid = true;
            for (int j=0; j<n-1; j++) {
                if (!sorted[j] && strs[j][i]>strs[j+1][i]) {
                    valid = false;
                    break;
                }
            }
            if (!valid) {
                res++;
                continue;
            }

            for (int j=0; j<n-1; j++) {
                if (!sorted[j] && strs[j][i]<strs[j+1][i]) {
                    sorted[j] = true;
                }
            }
        }
        return res;
    }
};
