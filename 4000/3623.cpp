// 3623. Count Number of Trapezoids I
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> ptNum;
        const int MOD = 1e9 + 7;

        long long res = 0, sum = 0;
        for (auto& p: points) {
            ptNum[p[1]]++;
        }

        for (auto& [_, pn] : ptNum) {
            long long edge = (long long)pn * (pn-1) / 2;
            res += edge*sum;
            sum += edge;
        }
        return res % MOD;
    }
};
