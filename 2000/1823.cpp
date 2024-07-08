// 1823. Find the Winner of the Circular Game
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> friends(n);
        for (int i=0; i<n; i++) friends[i] = 1;
        int idx = -1, nn=n;

        while (nn>1) {
            int kk = k;
            while (kk) {
                idx = (idx+1)%n;
                kk -= friends[idx];
            }
            friends[idx] = 0;
            nn--;
        }
        for (int i=0; i<n; i++)
            if (friends[i]) return i+1;
        return -1;
    }
};
