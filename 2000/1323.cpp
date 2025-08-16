// 1323. Maximum 69 Number
class Solution {
public:
    int maximum69Number (int num) {
        int n = num;
        int i=0, k = -1;
        while (n>0) {
            if (n%10 == 6) k = i;
            i++;
            n/=10;
        }
        if (k>=0)
            return num + 3 * pow(10,k);
        else
            return num;
    }
};
