// 3099. Harshad Number
class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sumOfDigits = 0, xx=x;
        while (xx) {
            sumOfDigits += (xx%10);
            xx/=10;
        }
        if (x%sumOfDigits==0) return sumOfDigits;
        else return -1;
    }
};
