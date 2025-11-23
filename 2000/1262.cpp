// 1262. Greatest Sum Divisible by Three
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> f = {0, INT_MIN, INT_MIN};
        for (int& n: nums) {
            vector<int> g = f;
            for (int i=0; i<3; i++) {
                g[(i+n%3)%3] = max(g[(i+n%3)%3], f[i]+n);
            }
            f = move(g);
        }
        return f[0];
    }
};
