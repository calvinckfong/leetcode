// 2078. Two Furthest Houses With Different Colors
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int l, r, res=0;

        for (r=n-1; r>=0; r--) {
            for (l=0; l<r; l++) {
                if (colors[l] != colors[r]) {
                    res = max(res, r-l);
                    break;
                }
            }
        }
        return res;
    }
};
