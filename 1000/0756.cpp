// 756. Pyramid Transition Matrix
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int n = bottom.length();
        for (auto& s: allowed) {
            tmp[s[0]-'A'][s[1]-'A'] |= 1 << (s[2]-'A');
        }
        
        vector<vector<int>> A(n, vector<int>(n, 0));
        int t = 0;
        for (char c: bottom) {
            A[n-1][t++] = c - 'A';
        }
        return solve(A, 0, n-1, 0);
    }

private:
    int tmp[7][7];
    set<long> seen;

    bool solve(vector<vector<int>>& A, long R, int n, int i) {
        if (n==1 && i==1) return true;
        if (i==n) {
            if (seen.find(R) != seen.end()) return false;
            seen.insert(R);
            return solve(A, 0, n-1, 0);
        } else {
            int w = tmp[A[n][i]][A[n][i+1]];
            for (int b=0; b<7; b++) {
                if (((w>>b)&1)!=0) {
                    A[n-1][i] = b;
                    if (solve(A, R*8+(b+1), n, i+1)) return true;
                }
            }
            return false;
        }
    }
};
