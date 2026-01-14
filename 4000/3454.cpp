// 3454. Separate Squares II
class SegTree {
public:
    SegTree(vector<int>& _xs) : xs(_xs) {
        n = xs.size() - 1;
        count.resize(4*n, 0);
        covered.resize(4*n, 0);
    }

    void update(int l, int r, int v) {
        modify(l, r, v, 0, n-1, 0);
    }

    int query() {
        return covered[0];
    }

private:
    int n;
    vector<int> xs;
    vector<int> count;
    vector<int> covered;

    void modify(int ql, int qr, int qv, int l, int r, int pos) {
        if (xs[r+1]<=ql || xs[l]>=qr) {
            return;
        }
        if (ql<=xs[l] && xs[r+1]<=qr) {
            count[pos] += qv;
        } else {
            int m = (l+r)/2;
            modify(ql, qr, qv, l, m, pos*2+1);
            modify(ql, qr, qv, m+1, r, pos*2+2);
        }

        if (count[pos]>0) {
            covered[pos] = xs[r+1] - xs[l];
        } else {
            if (l==r) {
                covered[pos] = 0;
            } else {
                covered[pos] = covered[pos*2+1] + covered[pos*2+2];
            }
        }
    }
};


class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<tuple<int, int, int, int>> events;
        set<int> xSet;

        for (auto& s: squares) {
            int x=s[0], y=s[1], l=s[2];
            int nx=x+l, ny=y+l;
            events.emplace_back(y, 1, x, nx);
            events.emplace_back(ny, -1, x, nx);
            xSet.insert(x);
            xSet.insert(nx);
        }

        sort(events.begin(), events.end());
        vector<int> xs(xSet.begin(), xSet.end());
        SegTree segTree(xs);
        vector<double> sums;
        vector<int> widths;
        double totalA = 0.0;
        int prev = get<0>(events[0]);

        for (auto& [y, d, x1, xr]: events) {
            int len = segTree.query();
            totalA += (double)len * (y-prev);
            segTree.update(x1, xr, d);
            sums.push_back(totalA);
            widths.push_back(segTree.query());
            prev = y;
        }

        long long tar = (long long)(totalA + 1)/2;
        int i = lower_bound(sums.begin(), sums.end(), tar) - sums.begin() - 1;
        double a = sums[i];
        int w = widths[i], h = get<0>(events[i]);

        return h + (totalA - a*2) / (w*2.0);
    }
};
