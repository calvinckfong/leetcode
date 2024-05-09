// 506. Relative Ranks
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<pair<int, int>> score_rank(n);
        for (int i=0; i<n; i++)
            score_rank[i] = {score[i], i};
        sort(score_rank.rbegin(), score_rank.rend());

        vector<string> result(n);
        result[score_rank[0].second] = "Gold Medal";
        if (n>1) result[score_rank[1].second] = "Silver Medal";
        if (n>2) result[score_rank[2].second] = "Bronze Medal";

        for (int i=3; i<n; i++)
            result[score_rank[i].second] = to_string(i+1);

        return result;
    }
};
