// 2338. Count the Number of Ideal Arrays
const int MOD = 1e9 + 7;
const int MAX_N = 1e4 + 10;
const int MAX_P = 15;
int c[MAX_N+MAX_P][MAX_P+1] = {0};
int sieve[MAX_N];

class Solution {
public:
    int idealArrays(int n, int maxValue) {
        init();

        long long result = 0;
        for (int i=1; i<=maxValue; i++) {
            long long mul = 1;
            for (int j: ps[i]) {
                mul = mul * c[n+j-1][j] % MOD;
            }
            result = (result + mul) % MOD;
        }
        return result;
    }
private:

    vector<int> ps[MAX_N];

    void init() {
        for (int i=2; i<MAX_N; i++) {
            if (sieve[i] == 0) {
                for (int j=i; j<MAX_N; j+=i)
                    sieve[j] = i;
            }
        }
        for (int i=2; i<MAX_N; i++) {
            int x = i;
            while (x>1) {
                int p = sieve[x];
                int cnt = 0;
                while (x%p == 0) {
                    x /= p;
                    cnt++;
                }
                ps[i].push_back(cnt);
            }
        }

        c[0][0] = 1;
        for (int i=1; i<MAX_N+MAX_P; i++) {
            c[i][0] = 1;
            for (int j=1; j<=min(i, MAX_P); j++) {
                c[i][j] = (c[i-1][j] + c[i-1][j-1]) % MOD;
            }
        }
    }
};
