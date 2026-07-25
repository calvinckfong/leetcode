// 3536. Maximum Product of Two Digits
class Solution {
public:
    int maxProduct(int n) {
        vector<int> dig;
        while (n>0) {
            dig.push_back(n%10);
            n/=10;
        }
        sort(dig.rbegin(), dig.rend());
        return dig[0]*dig[1];
    }
};
