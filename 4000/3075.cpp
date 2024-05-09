// 3075. Maximize Happiness of Selected Children
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long result=0;
        sort(happiness.begin(), happiness.end(), std::greater<int>());

        int cnt = 0;
        for (int i: happiness) {
            if (cnt>=k || cnt>=i) break;
            
            result += (i-cnt);
            cnt++;
        }

        return result;
    }
};
