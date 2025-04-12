// 3272. Find the Count of Good Integers
class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> dict;
        int base = pow(10, (n-1)/2);
        int skip = n&1;
        
        for (int i=base; i<base*10; i++) {
            string s = to_string(i);
            s += string(s.rbegin()+skip, s.rend());
            long long candidate = stoll(s);
            if (candidate%k == 0) {
                sort(s.begin(), s.end());
                dict.emplace(s);
            }
        }

        vector<long long> factorial(n+1, 1);
        long long result = 0;
        for (int i=1; i<=n; i++) {
            factorial[i] = factorial[i-1] * i;
        }

        for (auto& s: dict) {
            vector<int> cnt(10);
            for (const char& c: s) {
                cnt[c-'0']++;
            }

            long long total = (n-cnt[0]) * factorial[n-1];
            for (int& x: cnt) {
                total /= factorial[x];
            }
            result += total;
        }
        return result;
    }
};
