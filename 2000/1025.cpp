// 1025. Divisor Game
class Solution {
public:
    bool divisorGame(int n) {
        // As stated in the hint, if n is even, it can be made to odd by subtracting 1.
        // Therefore, Alice will win only when n is even
        return (n%2==0);
    }
};
