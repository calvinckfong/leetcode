// 1545. Find Kth Bit in Nth Binary String
class Solution {
public:
    char findKthBit(int n, int k) {
        if (n==1) return '0';

        int len = (1<<n) - 1;
        int mid = (len+1) / 2;
        if (k==mid) return '1';

        if (k<mid) return findKthBit(n-1, k);
        else return '1' - findKthBit(n-1, len-k+1) + '0';
    }
};
