// 2029. Stone Game IX
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0};
        for (int& x: stones) {
            cnt[x%3]++;
        }
        if (cnt[0]%2 == 0) {
            return cnt[1]>=1 && cnt[2]>=1;
        }
        return (cnt[1]-cnt[2])>2 || (cnt[2]-cnt[1])>2;
    }
};
