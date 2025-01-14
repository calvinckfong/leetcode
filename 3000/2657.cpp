// 2657. Find the Prefix Common Array of Two Arrays
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), commonCnt = 0;
        vector<int> result(n), freq(n+1);

        for (int i=0; i<n; i++) {
            if (++freq[A[i]] == 2) commonCnt++;
            if (++freq[B[i]] == 2) commonCnt++;

            result[i] = commonCnt;
        }

        return result;
    }
};
