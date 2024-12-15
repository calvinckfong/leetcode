// 1792. Maximum Average Pass Ratio
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto less = [](vector<int>&a, vector<int>&b) {
            double a0 = a[0], a1 = a[1];
            double b0 = b[0], b1 = b[1];
            return (a0+1.0)/(a1+1.0)-a0/a1 < (b0+1.0)/(b1+1.0)-b0/b1;
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(less)> pq(classes.begin(), classes.end(), less);

        while (--extraStudents>=0) {
            vector<int> c = pq.top();
            pq.pop();
            c[0]++;
            c[1]++;
            pq.push(c);
        }

        double result=0.0;
        while (!pq.empty()) {
            vector<int> c = pq.top();
            pq.pop();
            result += (double)c[0]/(double)c[1];
        }
        result /= classes.size();
        return result;
    }
};
