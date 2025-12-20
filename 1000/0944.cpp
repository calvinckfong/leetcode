// 944. Delete Columns to Make Sorted
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        int res = 0;
        for (int i=0; i<m; i++) {
            for (int j=1; j<n; j++) {
                if (strs[j-1][i] > strs[j][i]) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};
