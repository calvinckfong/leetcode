// 3483. Unique 3-Digit Even Numbers
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {0};
        for (int& d: digits) {
            freq[d]++;
        }

        int res = 0;
        for (int i=1; i<10; i++) {
            for (int j=0; j<10; j++) {
                for (int k=0; k<9; k+=2) {
                    res += freq[i] > 0 && freq[j]>(i==j) &&
                            freq[k] > (i==k) + (j==k);
                }
            }
        }
        return res;
    }
};
