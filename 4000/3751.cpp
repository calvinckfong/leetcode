// 3751. Total Waviness of Numbers in Range I
class Solution {
public:
    int totalWaviness(int num1, int num2) {
        return solve(num2) - solve(num1-1);
    }

private:
    long long cnt[16][10][10];
    long long sum[16][10][10];

    long long solve(int x) {
        if (x < 100) return 0;
        
        string s = to_string(x);

        memset(cnt, -1, sizeof(cnt));
        memset(cnt, -1, sizeof(sum));

        pair<long long, long long> res = dfs(0, -1, -1, s, true, true);
        return res.second;
    }

    pair<long long, long long> dfs(int pos, int prev, int curr, string s, 
        bool isLimit, bool isLeading) {
        int n = s.size();
        if (pos == n) return {1, 0};
        
        if (!isLimit && !isLeading && prev>=0 && curr>=0) {
            if (cnt[pos][prev][curr] != -1) {
                return {cnt[pos][prev][curr],
                    sum[pos][prev][curr]};
            }
        }

        long long _cnt = 0, _sum = 0;
        int up = isLimit?s[pos]-'0':9;
        for (int d=0; d<=up; d++) {
            bool nextLeading = isLeading && (d==0);
            bool nextLimit = isLimit&&(d==up);
            int nextPrev = curr;
            int nextCurr = nextLeading?-1:d;
            auto [subCnt, subSum] =
                dfs(pos+1, nextPrev, nextCurr, s, nextLimit, nextLeading);

            if (!nextLeading && prev>=0 && curr>=0) {
                if ((prev<curr && curr>d) ||
                    (prev>curr && curr<d)) {
                    _sum += subCnt;
                }
            }

            _cnt += subCnt;
            _sum += subSum;
        }

        if (!isLimit && !isLeading && prev>=0 && curr>=0) {
            cnt[pos][prev][curr] = _cnt;
            sum[pos][prev][curr] = _sum;
        }

        return {_cnt, _sum};
    }
};
