// 1318. Minimum Flips to Make a OR b Equal to c
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int bitMask=1, flip=0;
        for (int i=0; i<32; i++)
        {
            if (c&bitMask)
            {
                if (!(a&bitMask) && !(b&bitMask)) flip++;
            }
            else
            {
                if (a&bitMask) flip++;
                if (b&bitMask) flip++;
            }
            bitMask<<=1;
        }
        return flip;
    }
};
