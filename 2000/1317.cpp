// 1317. Convert Integer to the Sum of Two No-Zero Integers
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i=1; i<=n/2; i++) {
            if (noZero(i) && noZero(n-i)) {
                return {i, n-i};
            }
        }
        return {0, 0};
    }

private:
    bool noZero(int i) {
        while (i>9)
        {
            if (i%10 == 0) return false;
            i/=10;
        }
        return true;
    }
};
