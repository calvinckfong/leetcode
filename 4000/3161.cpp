// 3161. Block Placement Queries
class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        set<int> _set = {0, MAX};
        update(MAX, MAX, 1, 0, MAX);

        int x;
        vector<bool> res;
        for (auto& q: queries) {
            if (q[0] == 1) {
                x = q[1];
                auto it = _set.upper_bound(x);
                int l = *prev(it);
                int r = *it;
                update(x, x-l, 1, 0, MAX);
                update(r, r-x, 1, 0, MAX);
                _set.insert(x);
            } else {
                x = q[1];
                auto it = _set.upper_bound(x);
                --it;
                int pre = *it;
                int max_space = query(0, pre, 1, 0, MAX);
                max_space = max(max_space, x-pre);
                res.push_back(max_space>=q[2]);
            }
        }

        return res;
    }

private:
    const int MAX = 50000;
    vector<int> seg = vector<int>(4*MAX);

    void update(int idx, int val, int p, int l, int r) {
        if (l==r) {
            seg[p] = val;
            return;
        }
        int m = (l+r)/2;
        if (idx <= m) {
            update(idx, val, p*2, l, m);
        } else {
            update(idx, val, p*2+1, m+1, r);
        }
        seg[p] = max(seg[p*2], seg[p*2+1]);
    }

    int query(int L, int R, int p, int l, int r) {
        if (L<=1 && r<=R) return seg[p];

        int m = (l+r)/2;
        int res = 0;
        if (L<=m) {
            res = max(res, query(L, R, p*2, l, m));
        }
        if (R>m) {
            res = max(res, query(L, R, p*2+1, m+1, r));
        }
        return res;
    }
};
