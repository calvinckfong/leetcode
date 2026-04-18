// 3783. Mirror Distance of an Integer
class Solution {
public:
    int mirrorDistance(int n) {
        return abs(n - reverse(n));
    }

private:
    int reverse(int x) {
        int y = 0;
        while (x>0) {
            y = y*10 + x%10;
            x /= 10;
        }
        return y;
    }
};
