// 2211. Count Collisions on a Road
class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        if (n<=1) return 0;
        int l=0, r=n-1;

        while (l<n && directions[l] == 'L') l++;
        while (r>=0 && directions[r] == 'R') r--;

        int res = 0;
        for (int i=l; i<=r; i++) {
            res += (directions[i]!='S');
        }
        return res;
    }
};
