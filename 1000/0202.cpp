// 202. Happy Number
class Solution {
public:
    unordered_map<int, int> dp;
    bool isHappy(int n) {
        if (n==1) return true;
        else if (n<7) return false;

        int newN;
        if (dp[n]>0)
            return false;
        else
        {
            newN = 0;
            while (n)
            {
                newN += (n%10)*(n%10);
                n/=10;
            }
            if (newN==1) return true;
            dp[n] = newN; 
        }

        return isHappy(newN);
    }
};
