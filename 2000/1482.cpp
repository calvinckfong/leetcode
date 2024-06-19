// 1482. Minimum Number of Days to Make m Bouquets
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if ((long)m*(long)k>n) return -1;

        int l=100000, r=0;
        for (int i=0; i<n; i++) {
            l = min(l, bloomDay[i]);
            r = max(r, bloomDay[i]);
        }
        while (l<r) {
            int mid = (r+l)/2, flower=0, bouquest=0;
            for (int i=0; i<n; i++) {
                if (bloomDay[i]>mid) {
                    flower = 0;
                } else if (++flower>=k) {
                    bouquest++;
                    flower = 0;
                }
            }
            if (bouquest<m) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
