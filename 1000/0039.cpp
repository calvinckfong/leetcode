// 39. Combination Sum
class Solution {
public:
    vector<vector<int>> result;
    void Solve(vector<int>& candidates, vector<int>& sol, int target, int start) {
        if (target < 0) return;
        if (target == 0) {
            result.push_back(sol);
            return;
        }

        for (int i=start; i<candidates.size(); i++)
        {
            sol.push_back(candidates[i]);
            Solve(candidates, sol, target-candidates[i], i);
            sol.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        for (int i=0; i<candidates.size(); i++)
        {
            vector<int> sol({candidates[i]});
            Solve(candidates, sol, target-candidates[i], i);
        }
        return result;
    }
};
