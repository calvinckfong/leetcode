// 2999. Count the Number of Powerful Integers
class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string ss = to_string(start-1);
        string ee = to_string(finish);
        return countPowerful(ee, s, limit) - countPowerful(ss, s, limit); 
    }

private:
    long long countPowerful(string x, string s, int limit) {
        int xn = x.size(), sn = s.size();
        if (xn < sn) return 0;
        if (xn == sn) return (x>=s);

        int preLen = xn - sn;
        string suffix = x.substr(preLen, sn);
        long long count = 0;
        for (int i=0; i<preLen; i++) {
            if (limit < (x[i]-'0')) {
                count += (long)pow(limit+1, preLen-i);
                return count;
            }
            count += (long)(x[i]-'0') * (long)pow(limit+1, preLen-i-1);
        }
        if (suffix>=s) count++;
        return count;
    }
};
