// 2825. Make String a Subsequence Using Cyclic Increments
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        int idx2 = 0;
        for (int idx1=0; idx1<n1 && idx2<n2; ++idx1) {
            char c2 = str2[idx2];
            if (str1[idx1] == c2 || str1[idx1]+1 == c2 || str1[idx1]-25 == c2)
                idx2++;
        }
        return (idx2 == n2);
    }
};
