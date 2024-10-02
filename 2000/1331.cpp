// 1331. Rank Transform of an Array
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        map<int, vector<int>> indices;
        for (int i=0; i<n; i++) {
            indices[arr[i]].push_back(i);
        }

        int rank = 0;
        for (auto& p : indices) {
            rank++;
            for (int i: p.second) {
                arr[i] = rank;
            }
        }
        return arr;
    }
};
