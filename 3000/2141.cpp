// 2141. Maximum Running Time of N Computers
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());
        long long total = accumulate(batteries.begin(), batteries.end(), 0LL);
        int i = batteries.size()-1;
        while (i>0 && n>0 && total/n < batteries[i]) {
            total -= batteries[i];
            n--;
            i--;
        }
        
        return total/n;
    }
};
