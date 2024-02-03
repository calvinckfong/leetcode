class Solution {
public:
    unordered_map<int, int> hist;
    int climbStairs(int n) {
        if (n<=2) return n; 
        if (hist[n-2]==0)
            hist[n-2] = climbStairs(n-2);
        if (hist[n-1]==0)
            hist[n-1] = climbStairs(n-1);

        return hist[n-2] + hist[n-1];
    }
};
