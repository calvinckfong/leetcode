// 1886. Determine Whether Matrix Can Be Obtained By Rotation
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int k=0; k<4; k++) {
            if (equal(mat, target)) return true;
            rotate(mat);
        }
        return false;
    }

private:
    bool equal(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (a[i][j] != b[i][j]) return false;
            }
        }
        return true;
    }

    void rotate(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>> tmp(n, vector<int>(n));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                tmp[i][j] = a[n-j-1][i];
            }
        }
        a = tmp;
    }
};
