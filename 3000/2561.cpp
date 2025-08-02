// 2561. Rearranging Fruits
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int minVal = INT_MAX;
        unordered_map<int, int> freq;
        for (int& b: basket1) {
            freq[b]++;
            minVal = min(minVal, b);
        }
        for (int& b: basket2) {
            freq[b]--;
            minVal = min(minVal, b);
        }

        vector<int> merge;
        for (auto& [key, cnt]: freq) {
            if (cnt%2!=0) return -1;
            for (int i=0; i<abs(cnt)/2; i++) {
                merge.push_back(key);
            }
        }

        auto mid = merge.begin() + merge.size()/2;
        nth_element(merge.begin(), mid, merge.end());

        return accumulate(merge.begin(), mid, 0ll, 
            [&](long long res, int x) -> long long { 
                return res+min(minVal*2, x); 
            });
    }
};
