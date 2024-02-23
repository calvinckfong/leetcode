// 292. Nim Game
class Solution {
public:
    bool canWinNim(int n) {
        // you cannot win only when n is multiple of 4
        return (n%4!=0);
    }
};
