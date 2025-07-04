// 3307. Find the K-th Character in String Game II
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int t, res=0;
        while (k!=1) {
            t = __lg(k);
            if (((long long)1<<t) == k) t--;
            k = k - (1LL<<t);
            if (operations[t]) res++;
        }
        return 'a' + (res%26);
    }
};
