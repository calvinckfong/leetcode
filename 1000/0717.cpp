// 717. 1-bit and 2-bit Characters
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size(), i = n - 2;
        while (i>=0 && bits[i]>0) i--;
        return (n-i)%2 == 0;
    }
};
