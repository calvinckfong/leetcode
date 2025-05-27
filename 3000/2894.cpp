// 2894. Divisible and Non-divisible Sums Difference
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum = (n+1) * n / 2;
        int n3 = n/m;
        int num2 = ((n3+1) * (n3) / 2)*m;
        return sum - 2*num2;
    }
};
