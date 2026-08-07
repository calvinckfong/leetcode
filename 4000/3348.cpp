// 3348. Smallest Divisible Digit Product II
class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long tmp = t;
        for (int i=2; i<=9; i++) {
            while (tmp%i == 0) {
                tmp/=i;
            }
        }
        if (tmp>1) return "-1";

        int n = num.size();
        vector<long long> rem(n+1);
        rem[0] = t;
        int p = n-1;
        for (int i=0; i<n; i++) {
            if (num[i]=='0') {
                p = i;
                break;
            }
            rem[i+1] = rem[i] / gcd(rem[i], num[i]-'0');
        }
        if (rem[n]==1) return num;

        for (int i=p; i>=0; i--) {
            while (++num[i] <= '9') {
                long long new_t = rem[i] / gcd(rem[i], num[i]-'0');
                int k = 9;
                for (int j=n-1; j>i; j--) {
                    while (new_t % k) {
                        k--;
                    }
                    new_t /= k;
                    num[j] = '0' + k;
                }
                if (new_t == 1) return num;
            }
        }

        string res;
        for (int i=9; i>1; i--) {
            while (t%i == 0) {
                res += '0' + i;
                t /= i;
            }
        }
        res += string(max(n+1-(int)res.size(), 0), '1');
        ranges::reverse(res);
        return res;
    }
};
