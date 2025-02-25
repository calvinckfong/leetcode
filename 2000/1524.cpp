// 1524. Number of Sub-arrays With Odd Sum
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int mod = 1e9 + 7;
        int nEven=1, nOdd=0, sum=0, result=0;
        for (int num: arr) {
            sum += num;
            if (sum%2) {
                result += nEven;
                nOdd++;
            } else {
                result += nOdd;
                nEven++;
            }
            result %= mod;
        }
        return result;
    }
};
