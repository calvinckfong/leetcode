// 1497. Check If Array Pairs Are Divisible by k
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size(), rem;
        vector<int> count(k);

        for (int i=0; i<n; i++) {
            rem = ((arr[i] % k) + k) % k;
            count[rem]++;
        }
        
        if (count[0]%2) return false;
        for (int i=1; i<=k/2; i++) {
            if (count[i] != count[k-i]) return false;
        }
        return true;
    }
};
