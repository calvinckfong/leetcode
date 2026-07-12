// 1331. Rank Transform of an Array
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        std::vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

        unordered_map<int, int> mp;
        mp.reserve(sorted.size());
        for (int i=0; i<sorted.size(); i++) {
            mp[sorted[i]] = i+1;
        }
        for (int& x: arr) {
            x = mp[x];
        }
        
        return arr;
    }
};
