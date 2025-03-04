// 1780. Check if Number is a Sum of Powers of Three
class Solution {
public:
    bool checkPowersOfThree(int n) {
        int pow3 = pow(3, 14);
        int cnt = 0;

        while (n > 0 && pow3>0) {
            if (n >= pow3) {
                n -= pow3;
                cnt++;
            } else {
                pow3 /= 3;
                cnt=0;
            }
            if (cnt>1) return false;
        }
        return n==0;
    }
};
