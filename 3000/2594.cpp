// 2594. Minimum Time to Repair Cars
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        auto [minVal, maxVal] = minmax_element(ranks.begin(), ranks.end());

        vector<int> freq(*maxVal+1);
        for (int r: ranks) freq[r]++;

        long long l=1, r=(long long)(*minVal) * cars * cars;
        while (l<r) {
            long long mid = l + (r-l)/2;
            long long repaired = 0;

            for (int i=1; i<=*maxVal; i++)
                repaired += freq[i] * (long long)sqrt(mid / (long long)i);

            if (repaired>=cars) r = mid;
            else                l = mid+1;
        }
        return l;
    }
};
