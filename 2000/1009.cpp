// 1009. Complement of Base 10 Integer
class Solution {
public:
    int bitwiseComplement(int n) {
        int k = 0, nn = n;
        while (nn>>=1) {
            k++;
        }
        return (1<<(k+1)) - n - 1;
    }
};
