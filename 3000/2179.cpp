// 2179. Count Good Triplets in an Array
class FenwickTree
{
public:
    FenwickTree(int n) : tree(n+1, 0) {}

    int query(int idx) {
        idx++;
        int result = 0;
        while (idx>0) {
            result += tree[idx];
            idx -= idx & -idx;
        }
        return result;
    }

    void update(int idx, int delta) {
        idx++;
        while (idx < tree.size()) {
            tree[idx] += delta;
            idx += idx & -idx;
        }
    }

private:
    vector<int> tree;
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos2(n), reMap(n);
        for (int i=0; i<n; i++)
            pos2[nums2[i]] = i;
        for (int i=0; i<n; i++)
            reMap[pos2[nums1[i]]] = i;

        FenwickTree t(n);
        long long result = 0;
        for (int i=0; i<n; i++) {
            int pos = reMap[i];
            int l = t.query(pos);
            t.update(pos, 1);
            int r = (n-1-pos) - (i-l);
            result += (long long)l * r;
        }
        return result;
    }
};
