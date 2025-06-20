// 3443. Maximum Manhattan Distance After K Changes
class Solution {
public:
    int maxDistance(string s, int k) {
        int x=0, y=0, res=0;
        int n=s.size();
        for (int i=0; i<n; i++) {
            switch (s[i]) {
            case 'N': y++; break;
            case 'S': y--; break;
            case 'E': x++; break;
            case 'W': x--; break;
            }
            res = max(res, min(abs(x)+abs(y)+2*k, i+1));
        }
        return res;
    }
};
