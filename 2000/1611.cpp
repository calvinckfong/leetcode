// 1611. Minimum One Bit Operations to Make Integers Zero
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n==0) return 0;

        int k = 0, curr = 1;
        while (curr*2 <= n) {
            curr <<= 1;
            k++;
        }

        return (1<<(k+1)) - minimumOneBitOperations(n^curr) - 1;
    }
};
