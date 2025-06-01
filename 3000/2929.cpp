// 2929. Distribute Candies Among Children II

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long result = combination(n+2);
        result -= 3 * combination(n-limit+1);
        result += 3 * combination(n-limit*2);
        result -= combination(n-limit*3-1);

        return result;
    }

private:
    long long combination(int n) {
        if (n<0) return 0;
        return (long)n * (n-1) / 2;
    }
};
