// 1963. Minimum Number of Swaps to Make the String Balanced
class Solution {
public:
    int minSwaps(string s) {
        int ss = 0;
        for (char c: s) {
            if (c == '[') ss++;
            else if (ss>0) ss--;
        }
        return (ss+1)/2;
    }
};
