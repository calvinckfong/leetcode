// 1900. The Earliest and Latest Rounds Where Players Compete
class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        memset(F, 0, sizeof(F));
        memset(G, 0, sizeof(G));
        
        if (firstPlayer>secondPlayer)
            swap(firstPlayer, secondPlayer);

        pair<int, int> res = dp(n, firstPlayer, secondPlayer);
        return {res.first, res.second};
    }

private:
    int F[30][30][30];
    int G[30][30][30];

    pair<int, int> dp(int n, int f, int s) {
        if (F[n][f][s]) return {F[n][f][s], G[n][f][s]};

        if (f+s == n+1) return {1, 1};

        if (f+s > n+1) {
            tie(F[n][f][s], G[n][f][s]) = dp(n, n+1-s, n+1-f);
            return {F[n][f][s], G[n][f][s]};
        }

        int minV = INT_MAX, maxV = INT_MIN;
        int half = (n+1)/2;

        if (s<=half) {
            for (int i=0; i<f; i++) {
                for (int j=0; j<s-f; j++) {
                    auto [x, y] = dp(half, i+1, i+j+2);
                    minV = min(minV, x);
                    maxV = max(maxV, y);
                }
            }
        } else {
            int prime = n+1-s;
            int mid = (n-2*prime+1)/2;
            for (int i=0; i<f; i++) {
                for (int j=0; j<prime-f; j++) {
                    auto [x, y] = dp(half, i+1, i+j+mid+2);
                    minV = min(minV, x);
                    maxV = max(maxV, y);
                }
            }
        }
        return {F[n][f][s] = minV+1, G[n][f][s] = maxV+1};
    }
};
