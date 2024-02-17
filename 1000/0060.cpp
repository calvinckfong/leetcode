// 60. Permutation Sequence
class Solution {
public:
    int factorial(int n)
    {
        int result=1;
        while (n>1)
            result *= (n--);
        return result;
    }
    string getPermutation(int n, int k) {
        string s, result;
        for (int i=0; i<n; i++)
            s += to_string(i+1);

        k--; // convert to 0-indexed
        int nc = factorial(n); // number of combinations

        while (n)
        {
            nc/=n; n--;
            int idx = k/nc;
            result = result + s[idx];
            s.erase(idx, 1);
            k = k%nc;
        }

        return result;
    }
};
