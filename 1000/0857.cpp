// 857. Minimum Cost to Hire K Workers
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=quality.size();
        // compute and sort the wage-quality ratio
        vector<pair<double, int>> wq_ratio(n);
        for (int i=0; i<n; i++)
            wq_ratio[i] = {1.0*wage[i]/quality[i], i};
        sort(wq_ratio.begin(), wq_ratio.end());

        priority_queue<int> pq;
        int qSum = 0;
        double maxRatio = 0.0, result;
        // add workers according to the wage-quality ratio
        // i.e. choose cheaper worker first
        
        // before k workers are chosen, 
        // keep adding to queue and updating the pay amount
        for (int i=0; i<k; i++) {
            auto[ratio, index] = wq_ratio[i];
            qSum += quality[index];
            pq.push(quality[index]);
            maxRatio = max(maxRatio, ratio);
            result = maxRatio * qSum;
        }

        // add new worker to queue, and
        // pop the one with less quality
        for (int i=k; i<n; i++) {
            auto[ratio, index] = wq_ratio[i];
            maxRatio = max(maxRatio, ratio);
            qSum = qSum - pq.top() + quality[index];
            pq.pop();
            pq.push(quality[index]);
            result = min(result, maxRatio*qSum);
        }

        return result;
    }
};
