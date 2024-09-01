// 134. Gas Station
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int start=0, surplus=0, total_surplus=0;

        for (int i=0; i<n; i++) {
            int delta  = gas[i] - cost[i];
            total_surplus += delta;
            surplus += delta;
            if (surplus<0) {
                surplus = 0;
                start = i+1;
            }
        }
        return (total_surplus<0)?-1:start;
    }
};
