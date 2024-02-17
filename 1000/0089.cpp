// 89. Gray Code
class Solution {
public:
    // Generator of i-th gra code: `i xor (i/2)`
    vector<int> grayCode(int n) {

        vector<int> result(1<<n);
        for (int i=0; i<(1<<n); i++)
            result[i] = ( i^(i>>1) );

        return result;
    }
};
