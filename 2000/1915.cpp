// 1915. Number of Wonderful Substrings
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long result=0;
        long long count[1024] = {1}, mask=0;

        for (char c: word) {
            mask ^= 1<<(c-'a');
            result += count[mask];
            for (int i=0; i<10; i++)
                result += count[mask^(1<<i)];
            count[mask]++;
        }

        return result;
    }
};
