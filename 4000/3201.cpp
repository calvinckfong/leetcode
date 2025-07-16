// 3201. Find the Maximum Length of Valid Subsequence I
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int res = 0;
        const int pattern[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        for (int i=0; i<4; i++) {
            const int *p = pattern[i];
            int cnt = 0;
            for (int& n: nums) {
                cnt += (n%2 == p[cnt%2]);
            }
            res = max(res, cnt);
        }

        return res;
    }
};
