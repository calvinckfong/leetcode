// 3464. Maximize the Distance Between Points on a Square
class Solution {
public:
    int maxDistance(int _side, vector<vector<int>>& points, int _k) {
        k = _k;
        side = _side;
        for (auto&p : points) {
            int x = p[0], y = p[1];
            if (x == 0) {
                cand.push_back(y);
            } else if (y==side) {
                cand.push_back(side+x);
            } else if (x==side) {
                cand.push_back(3LL*side - y);
            } else {
                cand.push_back(4LL*side - x);
            }
        }
        sort(cand.begin(), cand.end());

        long long l = 1, r = side;
        int res = 0;
        while (l <= r) {
            long long m = (l+r) / 2;
            if (check(m)) {
                l = m + 1;
                res = m;
            } else {
                r = m - 1;
            }
        }
        return res;
    }

private:
    int side, k;
    vector<long long> cand;

    bool check(long long limit) {
        for (long long start: cand) {
            long long end = start + 4LL*side - limit;
            long long cur = start;
            for (int i=0; i<k-1; i++) {
                auto it = ranges::lower_bound(cand, cur+limit);
                if (it == cand.end() || *it > end) {
                    cur = -1;
                    break;
                }
                cur = *it;
            }
            if (cur >= 0) return true;
        }
        return false;
    }
};
