// 3264. Final Array State After K Multiplication Operations I
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        auto less = [](pair<int, int>&a, pair<int, int>&b){
            if (a.first == b.first) {
                return a.second > b.second;
            } 
            return a.first > b.first;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(less)> pq(less);
        int n = nums.size();
        for (int i=0; i<n; i++)
            pq.push({nums[i], i});

        while (k-->0) {
            auto p = pq.top();
            pq.pop();
            p.first *= multiplier;
            pq.push(p);
        }

        for (int i=0; i<n; i++) {
            auto p = pq.top();
            pq.pop();
            nums[p.second] = p.first;
        }
        return nums;
    }
};
