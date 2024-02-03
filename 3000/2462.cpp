// 2462. Total Cost to Hire K Workers
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long totalCost = 0;
        auto minmax = minmax_element(costs.begin(), costs.end());

        if (*minmax.first != *minmax.second)
        {
            while (k>0 && costs.size()>2*candidates)
            {
                auto c1 = min_element(costs.begin(), costs.begin()+candidates);
                auto c2 = min_element(costs.end()-candidates, costs.end());
                if (*c2<*c1)
                {
                    totalCost += *c2;
                    costs.erase(c2);
                }
                else
                {
                    totalCost += *c1;
                    costs.erase(c1);
                }
                k--;
            }
        }
        
        if (k>0)
        {
            sort(costs.begin(), costs.end());
            for (int i=0; i<k; i++)
                totalCost += costs[i];
        }
        return totalCost;
    }
};
