// 263. Ugly Number
class Solution {
public:
    bool isUgly(int n) {
        if (n<1) return false;
        if (n==1) return true;
        while (n>1)
        {
            if (n%2==0) { n/=2; continue; }
            else if (n%3==0) { n/=3; continue; }
            else if (n%5==0) { n/=5; continue; }

            if (n>1) return false;
        }
        return true;
    }
};
