// 2220. Minimum Bit Flips to Convert Number
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int result = 0, mask=1;
        for (int i=0; i<32; i++) {
            result += ((start&mask) != (goal&mask));
            mask <<= 1;
        }
        return result;
    }
};
