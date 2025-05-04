// 1128. Number of Equivalent Domino Pairs
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        unordered_map<int, int> count;
        for (auto& d : dominoes) {
            if (d[0] > d[1])
                count[d[1]*10 + d[0]]++;
            else
                count[d[0]*10 + d[1]]++;
        }

        int result = 0;
        for (auto& c : count) {
            int cnt = c.second;
            result += cnt * (cnt-1) / 2;
        }
        return result;
    }
};
