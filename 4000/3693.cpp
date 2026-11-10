// 3693. Climbing Stairs II
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int p1=0, p2=0, p3=0;
        for (int c: costs) {
            int cur = c + min({p1+1, p2+4, p3+9});
            p3 = p2; p2 = p1; p1 = cur;
        }
        return p1;
    }
};
