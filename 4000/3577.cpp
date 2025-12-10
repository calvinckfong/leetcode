// 3577. Count the Number of Computer Unlocking Permutations
class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const int MOD = 1e9 + 7; 
        int n = complexity.size();
        if (*min_element(complexity.begin()+1, complexity.end()) <= complexity[0]) return 0;

        int res = 1;
        for (int i=2; i<n; i++) {
            res = (long long)(res) * i % MOD;
        }
        return res;
    }
};
