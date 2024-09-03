// 1945. Sum of Digits of String After Convert
class Solution {
public:
    int getLucky(string s, int k) {
        int sum=0;
        for (char& c: s) {
            int v = c - 'a' + 1;
            sum += (v/10) + (v%10);
        }

        while (k>1) {
            int v = 0;
            while (sum>0) {
                v += (sum%10);
                sum/=10;
            }
            sum = v;
            k--;
        }

        return sum;
    }
};
