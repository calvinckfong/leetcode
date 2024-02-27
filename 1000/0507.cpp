// 507. Perfect Number
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num==1) return false;
        int sum=1;
        for (int i=2; i<=sqrt(num); i++)
        {
            if (num%i==0) 
                if (i != (num/i))
                    sum += (i + (num/i));
                else
                    sum += i;
        }
        return (num == sum);
    }
};
