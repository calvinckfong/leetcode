// 693. Binary Number with Alternating Bits
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int curr, last = -1;
        do {
            curr = n&1;
            if (curr == last) return false;
            last = curr;
            n >>= 1;
        } while (n);
        return true;
    }
};
