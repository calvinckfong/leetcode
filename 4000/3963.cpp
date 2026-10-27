// 3963. Create Grid With Exactly One Path
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res(m);
        res[0] = string(n, '.');
        string row = string(n-1, '#') + '.';
        for (int i=1; i<m; i++) {
            res[i] = row;
        }
        return res;
    }
};
