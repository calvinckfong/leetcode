// 1665. Minimum Initial Energy to Finish Tasks
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [&](vector<int>& a, vector<int>& b){
            return (a[1]-a[0]) > (b[1]-b[0]);
        });

        int res = 0, remain = 0;
        for (auto& t: tasks) {
            res += remain>t[1] ? 0 : t[1] - remain;
            remain = max(t[1]-t[0], remain-t[0]);
        }
        return res;
    }
};
