// 3343. Count Number of Balanced Permutations
class Solution {
public:
    int countBalancedPermutations(string num) {
        const int MOD = 1e9 + 7;
        
        int cnt[10] = {0};
        int total = 0, n = num.size();
        for (char& c: num) {
            int d = c-'0';
            cnt[d]++;
            total += d;
        }
        if (total % 2) return 0;

        int target = total/2;
        int maxOdd = (n+1)/2;
        vector<vector<long long>> comb(maxOdd+1, 
            vector<long long>(maxOdd+1));
        vector<vector<long long>> f(target+1, 
            vector<long long>(maxOdd+1));
        for (int i=0; i<=maxOdd; i++) {
            comb[i][i] = comb[i][0] = 1;
            for (int j=1; j<i; j++) {
                comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
            }
        }

        f[0][0] = 1;
        int psum = 0, tsum = 0;
        for (int i=0; i<10; i++) {
            psum += cnt[i];
            tsum += i * cnt[i];
            for (int oddCnt = min(psum, maxOdd);
                oddCnt>=max(0, psum-(n-maxOdd)); oddCnt--) 
            {    
                int evenCnt = psum - oddCnt;
                for (int curr = min(tsum, target);
                    curr>=max(0, tsum-target); curr--) 
                {    
                    long long res = 0;
                    for (int j=max(0, cnt[i]-evenCnt);
                        j<=min(cnt[i], oddCnt) && i*j<=curr; j++) 
                    {
                        long long ways = comb[oddCnt][j] * comb[evenCnt][cnt[i]-j] % MOD;
                        res = (res + ways * f[curr-i*j][oddCnt-j]%MOD) % MOD;
                    }
                    f[curr][oddCnt] = res;
                }
            }
        }
        return f[target][maxOdd];
    }
};
