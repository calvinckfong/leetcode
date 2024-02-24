// 441. Arranging Coins
class Solution {
public:
    int arrangeCoins(int n) {
        unsigned int k=0, i=0;
        while (k<n)
        {
            k += ++i;
        }
        return i - (k>n);
    }
};
