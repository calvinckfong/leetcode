// 40. Combination Sum II
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> combination;

        solve(candidates, target, result, combination, 0);

        return result;
    }

    void solve(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& combination, int index) {
        if (target==0) {
            result.push_back(combination);
            return;
        }
        for (int i=index; i<candidates.size() && target>=candidates[i]; i++) {
            if (i==index || candidates[i]!=candidates[i-1]) {
                combination.push_back(candidates[i]);
                solve(candidates, target-candidates[i], result, combination, i+1);
                combination.pop_back();
            }
        }
    }
};
