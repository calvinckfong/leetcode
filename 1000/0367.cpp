// 367. Valid Perfect Square
class Solution {
public:
    bool isPerfectSquare(int num) {
        long k=0, n=1;
        do {
            if (k==num) return true;
            k += n;
            n += 2; 
        } while (k<=num);
        return false;
    }
};
