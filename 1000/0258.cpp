// 258. Add Digits
class Solution {
public:
    int addDigits(int num) {
        int sum, tmp;
        while (num>9)
        {
            sum=0; tmp=num;
            while (tmp)
            {
                sum += tmp%10;
                tmp/=10;
            }
            num = sum;
        }
        return num;
    }
};
