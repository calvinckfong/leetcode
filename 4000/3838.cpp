// 3838. Weighted Word Mapping
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res;
        for (auto& w: words) {
            int sum = 0;
            for (auto c: w) {
                sum += weights[c-'a'];
            }
            res.push_back('z' - (sum%26));
        }

        return res;
    }
};
