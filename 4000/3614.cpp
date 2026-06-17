// 3614. Process String with Special Operations II
class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;
        for (auto& c: s) {
            if (c == '*')       len = max(len-1, 0LL);
            else if (c == '#')  len *= 2;
            else if (c != '%')  len++;
        }

        if (k>=len) return '.'; 

        for (int i=s.size()-1; i>=0; i--) {
            switch (s[i]) {
            case '*':
                len++;
                break;
            case '#':
                if (k+1>(len+1)/2) k -= (len+1)/2;
                len = (len+1)/2;
                break;
            case '%':
                k = len - 1 - k;
                break;
            default:
                if (k+1 == len) return s[i];
                else len--;
            }
        }

        return '.';
    }
};
