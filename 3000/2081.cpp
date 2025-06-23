// 2081. Sum of k-Mirror Numbers
class Solution {
private:
    int digit[100];

    bool isPalindrome(long long x, int k) {
        int len = -1;
        while (x) {
            len++;
            digit[len] = x%k;
            x /= k;
        }
        for (int i=0, j=len; i<j; i++, j--) {
            if (digit[i] != digit[j]) return false;
        }
        return true;
    }

public:
    long long kMirror(int k, int n) {
        int l = 1, count = 0;
        long long res = 0;
        while (count<n) {
            int r = l*10;
            for (int op=0; op<2; op++) {
                for (int i=l; i<r && count<n; i++) {
                    long long comb = i;
                    int x = (op==0)?i/10:i;
                    while (x) {
                        comb = comb*10 + (x%10);
                        x/=10;
                    }
                    if (isPalindrome(comb, k)) {
                        count++;
                        res += comb;
                    }
                }
            }
            l = r;
        }
        return res;
    }
};
