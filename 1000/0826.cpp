// 826. Most Profit Assigning Work
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        vector<pair<int, int>> projects(n);
        for (int i=0; i<n; i++)
            projects[i] = {profit[i], difficulty[i]};
        sort(projects.rbegin(), projects.rend());

        int result=0;
        for (int w: worker) {
            for (int i=0; i<n; i++) {
                if (projects[i].second <= w) {
                    result += projects[i].first;
                    break;
                }
            }
        }
        return result;
    }
};
