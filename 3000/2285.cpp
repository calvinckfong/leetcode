// 2285. Maximum Total Importance of Roads
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> weights;
        for (int i=0; i<n; i++) weights.push_back({i, 0});
        for (int i=0; i<roads.size(); i++) {
            weights[roads[i][0]].second++;
            weights[roads[i][1]].second++;
        }
        sort(weights.begin(), weights.end(), [=](pair<int,int>&a,pair<int,int>&b){
            return a.second<b.second;
        });
        for (int i=0; i<n; i++) {
            weights[i].second = i+1;
        }
        sort(weights.begin(), weights.end());
        long long result = 0;
        for (int i=0; i<roads.size(); i++) {
            result += weights[roads[i][0]].second;
            result += weights[roads[i][1]].second;
        }
        return result;
    }
};
