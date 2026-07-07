// 3754. Concatenate Non-Zero Digits and Multiply by Sum I
class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0;
        string x;
        while (n>0) {
            int i = n%10;
            n /= 10;
            if (i>0) {
                x = (char)('0'+i) + x;
                sum += i;
            }
        }

        if (x.empty()) return 0;
        return stoll(x) * sum;
    }
};
