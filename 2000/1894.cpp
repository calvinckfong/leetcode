// 1894. Find the Student that Will Replace the Chalk
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        if (n==1) return 0;

        long long sum=0;
        for (int i=0; i<n; i++) {
            sum += chalk[i];
            if (sum>k) return i;
        }

        int i=0;
        k %= sum;
        while (k >= chalk[i]) {
            k -= chalk[i];
            i = (i+1)%n;
        }
        return i;
    }
};
